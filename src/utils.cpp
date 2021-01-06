#include "utils.h"

CRGB colourFraction(CRGB colourIn, float fraction)
{
    fraction = min(1.0f, fraction);
    return CRGB(colourIn).fadeToBlackBy(255 * (1.0f - fraction));
}

void drawPixels(float position, float count, CRGB colour)
{
    float availFirstPixel = 1.0f - (position - (long)(position));
    float amtFirstPixel = min(availFirstPixel, count);
    float remaining = min(count, FastLED.size() - position);
    int pos = position;

    if (remaining > 0.0f)
    {
        FastLED.leds()[pos++] += colourFraction(colour, amtFirstPixel);
        remaining -= amtFirstPixel;
    }

    while (remaining > 1.0f)
    {
        FastLED.leds()[pos++] += colour;
        remaining--;
    }

    if (remaining > 0.0f)
    {
        FastLED.leds()[pos++] += colourFraction(colour, remaining);
    }
}
