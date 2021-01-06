#include "bounce.h"
#include "utils.h"

void BounceEffect::draw()
{
    for (size_t i = 0; i < length + 1; i++)
        if (fadeRate != 0)
            leds[i].fadeToBlackBy(fadeRate);
        else
            leds[i] = CRGB::Black;

    for (size_t i = 0; i < ballCount; i++)
    {
        double timeSinceLastBounce = (unixTime() - clockTimeAtLastBounce[i]) / speedFactor;
        height[i] = 0.5 * g * pow(timeSinceLastBounce, 2.0) + ballSpeed[i] * timeSinceLastBounce;

        if (height[i] < 0)
        {
            height[i] = 0;
            ballSpeed[i] = dampening[i] * ballSpeed[i];
            clockTimeAtLastBounce[i] = unixTime();

            if (ballSpeed[i] < 1.0)
            {
                ballSpeed[i] = initialBallSpeed(startHeight) * dampening[i];
            }
        }

        size_t position = (size_t)(height[i] * (length - 1) / startHeight);

        leds[position] += colours[i];
        leds[position + 1] += colours[i];

        if (mirrorFlag)
        {
            leds[length - 1 - position] += colours[i];
            leds[length - position] += colours[i];
        }
    }

    delay(20);
}

double BounceEffect::initialBallSpeed(double height) const
{
    return sqrt(-2 * g * height);
}
