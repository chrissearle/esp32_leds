#include <Arduino.h>

#include "display.h"
#include "effect.h"

#define FASTLED_INTERNAL
#include <FastLED.h>

// 2812 LEDs

#define NUM_LEDS 128
#define LED_PIN 5

CRGB g_LEDs[NUM_LEDS] = {0};

#include "rainbow.h"
#include "marquee.h"
#include "twinkle.h"
#include "comet.h"
#include "bounce.h"
#include "kr.h"
#include "cylon.h"

NokiaDisplay *display;

RainbowEffect *rainbow;
MarqueeEffect *marquee;
TwinkleEffect *twinkle;
CometEffect *comet;
BounceEffect *bounce;
KnightRiderEffect *kitt;
CylonEffect *cylon;

uint32_t maxPower = 800;
uint8_t brightness = 255;

void setup()
{
  pinMode(LED_PIN, OUTPUT);

  display = new NokiaDisplay();

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(g_LEDs, NUM_LEDS);
  FastLED.setBrightness(brightness);
  FastLED.setMaxPowerInMilliWatts(maxPower);

  rainbow = new RainbowEffect(g_LEDs, NUM_LEDS);
  marquee = new MarqueeEffect(g_LEDs, NUM_LEDS);
  twinkle = new TwinkleEffect(g_LEDs, NUM_LEDS);
  comet = new CometEffect(g_LEDs, NUM_LEDS);
  bounce = new BounceEffect(g_LEDs, NUM_LEDS, 5, 64, false);
  kitt = new KnightRiderEffect(g_LEDs, NUM_LEDS);
  cylon = new CylonEffect(g_LEDs, NUM_LEDS);
}

int effectTimeLeft(double runTimeSecs, double effectDuration)
{
  return (int)(effectDuration - (runTimeSecs - (floor(runTimeSecs / effectDuration) * effectDuration))) + 1;
}

void updateScreen(unsigned int fps, const char *effect, int timeToChange)
{
  EVERY_N_MILLISECONDS(250)
  {
    display->clear();

    display->writeInt(3, 1, "FPS", fps, "");
    display->writeInt(3, 2, "P", calculate_unscaled_power_mW(g_LEDs, NUM_LEDS), " mW");
    display->writeDouble(3, 3, "B", calculate_max_brightness_for_power_mW(brightness, maxPower), "");
    display->writeLine(3, 4, effect);
    display->writeInt(3, 5, "Next", timeToChange, "");

    display->update();
  }
}

void loop()
{
  double effectDuration = 30.0;
  double startSecs = millis() / 1000.0;
  Effect *lastEffect = nullptr;
  Effect *effect = nullptr;

  for (;;)
  {
    double runTimeSecs = (millis() / 1000.0) - startSecs;

    switch ((int)(runTimeSecs / effectDuration) % 7)
    {
    case 0:
      effect = cylon;
      break;
    case 1:
      effect = kitt;
      break;
    case 2:
      effect = bounce;
      break;
    case 3:
      effect = comet;
      break;
    case 4:
      effect = twinkle;
      break;
    case 5:
      effect = marquee;
      break;
    default:
      effect = rainbow;
      break;
    }

    if (lastEffect != effect)
    {
      FastLED.clear();
      lastEffect = effect;
    }

    updateScreen(FastLED.getFPS(), effect->getName(), effectTimeLeft(runTimeSecs, effectDuration));

    effect->draw();

    FastLED.show();
  }
}