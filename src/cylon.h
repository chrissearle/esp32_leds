#ifndef CYLON_H_
#define CYLON_H_

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class CylonEffect : public Effect
{
private:
    const int width = 15;

public:
    CylonEffect(CRGB *data, int ledCount) : Effect(data, ledCount, "Cylon"){};
    void draw();
};

#endif // CYLON_H_
