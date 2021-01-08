#pragma once

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class MarqueeEffect : public Effect
{
public:
    MarqueeEffect(int ledCount) : Effect(ledCount, "Marquee"){};
    void draw();
};
