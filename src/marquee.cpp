#include "marquee.h"

void MarqueeEffect::draw()
{
    static byte j = HUE_BLUE;

    j += 4;

    byte k = j;

    CRGB c;

    static int scroll = 0;
    scroll++;

    for (int i = 0; i < length; i++)
        leds[i] = c.setHue(k += 8);

    for (int i = scroll % 5; i < length; i += 5)
        leds[i] = CRGB::Black;

    delay(50);
}