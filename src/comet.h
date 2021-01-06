#pragma once

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class CometEffect : public Effect
{
private:
    byte fadeAmt = 64;
    int cometSize = 5;
    int deltaHue = 4;
    byte hue = HUE_RED;
    int direction = 1;
    double position = 0;
    double speed = 0.5;

public:
    CometEffect(CRGB *data, int ledCount) : Effect(data, ledCount, "Comet"){};
    void draw();
};
