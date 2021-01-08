#include "comet.h"

void CometEffect::draw()
{
    EVERY_N_MILLISECONDS(20)
    {
        hue += deltaHue;
        position += direction * speed;

        if (position == (length - cometSize) || position == 0)
            direction *= -1;

        for (int i = 0; i < cometSize; i++)
            leds[(int)position + i].setHue(hue);

        for (int j = 0; j < length; j++)
            if (random(2) == 1)
                leds[j] = leds[j].fadeToBlackBy(fadeAmt);
    }
}
