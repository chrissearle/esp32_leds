#include "fire.h"
#include "utils.h"

void FireEffect::draw()
{
    EVERY_N_MILLISECONDS(20)
    {
        clearPixels();

        // Cool each a little bit
        for (int i = 0; i < length; i++)
        {
            heat[i] = max(0L, heat[i] - random(0, ((cooling * 10) / length) + 2));
        }

        // Drift heat up
        for (int i = 0; i < length; i++)
        {
            heat[i] = (heat[i] * blendSelf +
                       heat[(i + 1) % length] * blendNeighbour1 +
                       heat[(i + 2) % length] * blendNeighbour2 +
                       heat[(i + 3) % length] * blendNeighbour3) /
                      blendTotal;
        }

        // Ignite some new sparks in the hot area
        for (int i = 0; i < sparks; i++)
        {
            if (random(255) < sparking)
            {
                int y = length - 1 - random(sparkHeight);
                heat[y] = heat[y] + random(160, 255); // can roll over - keep if looks good - clamp if not
            }
        }

        // Convert heat to colour
        for (int i = 0; i < length; i++)
        {
            CRGB colour = HeatColor(heat[i]);
            int j = reversed ? (length - 1 - i) : i;
            drawPixels(j, 1, colour);
            if (mirrored)
            {
                int j2 = !reversed ? (2 * length - 1 - i) : length + i;
                drawPixels(j2, 1, colour);
            }
        }
    }
}
