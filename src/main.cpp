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

NokiaDisplay *display;

RainbowEffect *rainbow;
MarqueeEffect *marquee;
TwinkleEffect *twinkle;
CometEffect *comet;
BounceEffect *bounce;

void setup()
{
  pinMode(LED_PIN, OUTPUT);

  display = new NokiaDisplay();

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(g_LEDs, NUM_LEDS);
  FastLED.setBrightness(255);
  FastLED.setMaxPowerInMilliWatts(800);

  rainbow = new RainbowEffect(g_LEDs, NUM_LEDS);
  marquee = new MarqueeEffect(g_LEDs, NUM_LEDS);
  twinkle = new TwinkleEffect(g_LEDs, NUM_LEDS);
  comet = new CometEffect(g_LEDs, NUM_LEDS);
  bounce = new BounceEffect(g_LEDs, NUM_LEDS, 5, 64, false);
}

double framesPerSecond(double seconds)
{
  static double framesPerSecond;

  framesPerSecond = (framesPerSecond * 0.9) + (1.0 / seconds * 0.1);

  return framesPerSecond;
}

int effectTimeLeft(double runTimeSecs, double effectDuration)
{
  return (int)(effectDuration - (runTimeSecs - (floor(runTimeSecs / effectDuration) * effectDuration))) + 1;
}

void updateScreen(double fps, const char *effect, int timeToChange)
{
  static unsigned long msLastUpdate = millis();

  if (millis() - msLastUpdate > 250)
  {
    display->clear();

    display->writeDouble(3, 1, "FPS", fps, "");
    display->writeInt(3, 2, "P", calculate_unscaled_power_mW(g_LEDs, NUM_LEDS), " mW");
    display->writeLine(3, 3, effect);
    display->writeInt(3, 4, "Next", timeToChange, "");

    display->update();

    msLastUpdate = millis();
  }
}

void loop()
{
  double effectDuration = 30.0;
  double fps = 0.0;
  double startSecs = millis() / 1000.0;
  Effect *lastEffect = nullptr;
  Effect *effect = nullptr;

  for (;;)
  {
    double frameStartSecs = millis() / 1000.0;

    double runTimeSecs = frameStartSecs - startSecs;

    switch ((int)(runTimeSecs / effectDuration) % 5)
    {
    case 0:
      effect = bounce;
      break;
    case 1:
      effect = comet;
      break;
    case 2:
      effect = twinkle;
      break;
    case 3:
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

    updateScreen(fps, effect->getName(), effectTimeLeft(runTimeSecs, effectDuration));

    effect->draw();

    FastLED.show();

    double frameEndSecs = millis() / 1000.0;
    fps = framesPerSecond(frameEndSecs - frameStartSecs);
  }
}