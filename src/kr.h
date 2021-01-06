#ifndef KR_H_
#define KR_H_

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class KnightRiderEffect : public Effect
{
private:
    const int width = 15;

public:
    KnightRiderEffect(CRGB *data, int ledCount) : Effect(data, ledCount, "K.Rider"){};
    void draw();
};

#endif // KR_H_
