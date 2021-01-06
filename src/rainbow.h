#pragma once

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class RainbowEffect : public Effect
{
private:
    int initialHue = 0;
    const int hueDensity = 4;
    const int deltaHue = 16;

public:
    RainbowEffect(CRGB *data, int ledCount) : Effect(data, ledCount, "Rainbow"){};
    void draw();
};
