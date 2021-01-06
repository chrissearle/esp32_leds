#include "twinkle.h"
#include "utils.h"

static const CRGB colours[] = {
    CRGB::Red,
    CRGB::Blue,
    CRGB::Purple,
    CRGB::Green,
    CRGB::Orange};

void TwinkleEffect::draw()
{
    passCount++;

    if (passCount >= length)
    {
        passCount = 0;

        for (int i = 0; i < length; i++)
            leds[i] = CRGB::Black;
    }

    leds[random(length)] = colours[random(ARRAYSIZE(colours))];
}