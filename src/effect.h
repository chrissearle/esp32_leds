#pragma once

#define FASTLED_INTERNAL
#include <FastLED.h>

class Effect
{
protected:
    CRGB *leds;
    int length;
    const char *name;

public:
    Effect(CRGB *data, int ledCount, const char *effectName) : leds(data), length(ledCount), name(effectName){};
    virtual void draw() = 0;
    const char *getName()
    {
        return name;
    }
};
