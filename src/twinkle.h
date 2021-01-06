#ifndef TWINKLE_H_
#define TWINKLE_H_

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class TwinkleEffect : public Effect
{
private:
    int passCount = 0;

public:
    TwinkleEffect(CRGB *data, int ledCount) : Effect(data, ledCount, "Twinkle"){};
    void draw();
};

#endif // TWINKLE_H_