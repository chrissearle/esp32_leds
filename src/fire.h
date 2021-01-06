#pragma once

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class FireEffect : public Effect
{
private:
    int cooling;
    int sparks;
    int sparkHeight;
    int sparking;
    bool reversed;
    bool mirrored;

    byte *heat;

    static const byte blendSelf = 2;
    static const byte blendNeighbour1 = 3;
    static const byte blendNeighbour2 = 2;
    static const byte blendNeighbour3 = 1;
    static const byte blendTotal = (blendSelf + blendNeighbour1 + blendNeighbour2 + blendNeighbour3);

public:
    FireEffect(int ledCount, int cooling = 20, int sparking = 100, int sparks = 3, int sparkHeight = 4,
               bool reversed = false, bool mirrored = false) : Effect(ledCount, "Fire"),
                                                               cooling(cooling),
                                                               sparks(sparks),
                                                               sparkHeight(sparkHeight),
                                                               sparking(sparking),
                                                               reversed(reversed),
                                                               mirrored(mirrored)
    {
        if (mirrored)
            length = length / 2;

        heat = new byte[length]{0};
    };

    virtual ~FireEffect()
    {
        delete[] heat;
    }

    void draw();
};
