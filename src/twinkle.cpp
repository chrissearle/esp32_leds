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

        clearPixels();
    }

    drawPixels(random(length), 1, colours[random(ARRAYSIZE(colours))]);
}
