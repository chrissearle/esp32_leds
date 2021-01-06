#pragma once

#include <sys/time.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#define ARRAYSIZE(x) (sizeof(x) / sizeof(x[0]))

extern CRGB colourFraction(CRGB colourIn, float fraction);

extern void drawPixels(float position, float count, CRGB colour);

inline void clearPixels()
{
    FastLED.clear();
}

inline double unixTime()
{
    timeval tv = {0};
    gettimeofday(&tv, nullptr);
    return (double)(tv.tv_usec / 1000000.0 + (double)tv.tv_sec);
}
