#pragma once

#define FASTLED_INTERNAL
#include <FastLED.h>

using namespace std;
#include <vector>

#include "effect.h"
#include "utils.h"

static const CRGB ballColours[] = {
    CRGB::Green,
    CRGB::Red,
    CRGB::Blue,
    CRGB::Orange,
    CRGB::Indigo};

class BounceEffect : public Effect
{
private:
    size_t ballCount;
    byte fadeRate;
    bool mirrorFlag;
    double impactVelocity;

    const double g = -9.81;
    const double startHeight = 1;
    const double speedFactor = 10.0;

    vector<double> clockTimeAtLastBounce, height, ballSpeed, dampening;
    vector<CRGB> colours;

    double initialBallSpeed(double height) const;

public:
    BounceEffect(CRGB *data, int ledCount, size_t balls, byte fade, bool mirror)
        : Effect(data, ledCount - 1, "Bounce"),
          ballCount(balls),
          fadeRate(fade),
          mirrorFlag(mirror),
          clockTimeAtLastBounce(balls),
          height(balls),
          ballSpeed(balls),
          dampening(balls),
          colours(balls)
    {
        impactVelocity = initialBallSpeed(startHeight);

        for (size_t i = 0; i < ballCount; i++)
        {
            height[i] = startHeight;
            clockTimeAtLastBounce[i] = unixTime();
            dampening[i] = 1.0 - i / pow(ballCount, 2);
            ballSpeed[i] = initialBallSpeed(height[i]);
            colours[i] = ballColours[i % ARRAYSIZE(ballColours)];
        }
    };

    void draw();
};
