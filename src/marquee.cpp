#include "marquee.h"
#include "utils.h"

void MarqueeEffect::draw()
{
    EVERY_N_MILLISECONDS(50)
    {
        static byte j = HUE_BLUE;

        j += 4;

        byte k = j;

        CRGB c;

        static int scroll = 0;
        scroll++;

        for (int i = 0; i < length; i++)
            drawPixels(i, 1, c.setHue(k += 8));

        for (int i = scroll % 5; i < length; i += 5)
            drawPixels(i, 1, CRGB::Black);
    }
}
