#pragma once

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class MarqueeEffect : public Effect
{
public:
    MarqueeEffect(CRGB *data, int ledCount) : Effect(data, ledCount, "Marquee"){};
    void draw();
};
