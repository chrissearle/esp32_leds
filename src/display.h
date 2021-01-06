#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

class NokiaDisplay
{
private:
    U8G2 *screen;
    int lineHeight = 0;

public:
    NokiaDisplay();
    void writeLine(int indent, int line, const char *msg);
    void writeDouble(int indent, int line, const char *prefix, double value, const char *suffix);
    void writeInt(int indent, int line, const char *prefix, unsigned int value, const char *suffix);
    void clear();
    void update();
};

#endif // DISPLAY_H_