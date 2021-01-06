#include "rainbow.h"

void RainbowEffect::draw()
{
    fill_rainbow(leds, length, initialHue += hueDensity, deltaHue);
}