#include "kr.h"

void KnightRiderEffect::draw()
{
    EVERY_N_MILLISECONDS(20)
    {
        fadeToBlackBy(leds, length, 64);
        int position = beatsin16(32, 0, length - width);
        for (int i = position; i < position + width; i++)
            leds[i] = CRGB::Red;
    }
}