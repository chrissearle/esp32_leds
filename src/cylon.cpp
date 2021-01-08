#include "cylon.h"
#include "utils.h"

void CylonEffect::draw()
{
    EVERY_N_MILLISECONDS(20)
    {
        fadeToBlackBy(leds, length, 64);
        int position = beatsin16(32, 0, length - width);
        byte hue = beatsin8(96);
        for (int i = position; i < position + width; i++)
            drawPixels(i, 1, CHSV(hue, 255, 255));
    }
}
