#include "leaf.h"
#include <FastLED.h>

#define FLOWER_ONE_LEDS 5
#define FLOWER_TWO_LEDS 3
#define FLOWER_ONE_PIN 6
#define FLOWER_TWO_PIN 7
#define LED_TYPE WS2811
#define COLOR_ORDER RGB

CRGB flowerOne[FLOWER_ONE_LEDS];
CRGB flowerTwo[FLOWER_TWO_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, FLOWER_ONE_PIN, COLOR_ORDER>(flowerOne, FLOWER_ONE_LEDS);
  FastLED.addLeds<LED_TYPE, FLOWER_TWO_PIN, COLOR_ORDER>(flowerTwo, FLOWER_TWO_LEDS);
  FastLED.clear();
}

void loop() {
  flowerOne[0] = CRGB::Red;
  flowerTwo[0] = CRGB::Red;
  FastLED.show();
}