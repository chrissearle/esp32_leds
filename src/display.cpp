#include "display.h"

#define SCREEN_CLK 14
#define SCREEN_DATA 13
#define SCREEN_CS 15
#define SCREEN_DC 27
#define SCREEN_RESET 26

NokiaDisplay::NokiaDisplay()
{
    screen = new U8G2_PCD8544_84X48_F_4W_SW_SPI(U8G2_R2, SCREEN_CLK, SCREEN_DATA, SCREEN_CS, SCREEN_DC, SCREEN_RESET);

    screen->begin();
    screen->setFont(u8g2_font_6x10_tf);
    lineHeight = screen->getFontAscent() - screen->getFontDescent();
}

void NokiaDisplay::clear()
{
    screen->clearBuffer();
}

void NokiaDisplay::update()
{
    screen->sendBuffer();
}

void NokiaDisplay::writeLine(int indent, int line, const char *msg)
{
    screen->setCursor(indent, lineHeight * line + 2);
    screen->print(msg);
}

void NokiaDisplay::writeDouble(int indent, int line, const char *prefix, double value, const char *suffix)
{
    char str[12];
    snprintf(str, sizeof(str), "%s: %.1lf%s", prefix, value, suffix);
    writeLine(indent, line, str);
}

void NokiaDisplay::writeInt(int indent, int line, const char *prefix, unsigned int value, const char *suffix)
{
    char str[12];
    snprintf(str, sizeof(str), "%s: %u%s", prefix, value, suffix);
    writeLine(indent, line, str);
}
