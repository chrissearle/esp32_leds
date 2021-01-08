#pragma once

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class TwinkleEffect : public Effect
{
private:
    int passCount = 0;

public:
    TwinkleEffect(int ledCount) : Effect(ledCount, "Twinkle"){};
    void draw();
};
