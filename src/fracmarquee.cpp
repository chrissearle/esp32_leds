#include "fracmarquee.h"
#include "utils.h"

void FractionalMarqueeEffect::draw()
{
    EVERY_N_MILLISECONDS(20)
    {
        clearPixels();

        scroll += 0.1f;

        if (scroll > 5.0)
            scroll -= 5.0;

        for (float i = scroll; i < length / 2 - 1; i += 5)
        {
            drawPixels(i, 3, CRGB::Green);
            drawPixels(length - 1 - (int)i, 3, CRGB::Red);
        }
    }
}
