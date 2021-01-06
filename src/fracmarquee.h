#pragma once

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class FractionalMarqueeEffect : public Effect
{
private:
    float scroll = 0.0f;

public:
    FractionalMarqueeEffect(int ledCount) : Effect(ledCount, "F.Marquee"){};
    void draw();
};
