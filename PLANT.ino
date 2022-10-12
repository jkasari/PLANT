#include "Petal.h"
#include <FastLED.h>

#define FLOWER_ONE_LEDS 5
#define FLOWER_TWO_LEDS 3
#define FLOWER_ONE_PIN 6
#define FLOWER_TWO_PIN 7
#define POT_READ A1
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
#define MASTER_BRIGHTNESS 125
#define COLOR_NORMAL true
#define COLOR_INVERSE false


// Create the correct number of CRGB objects and Petal objects to feed them color. 
CRGB flowerOne[FLOWER_ONE_LEDS];
CRGB flowerTwo[FLOWER_TWO_LEDS];
Petal petalsOne[FLOWER_ONE_LEDS];
Petal petalsTwo[FLOWER_TWO_LEDS];

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<LED_TYPE, FLOWER_ONE_PIN, COLOR_ORDER>(flowerOne, FLOWER_ONE_LEDS);
  FastLED.addLeds<LED_TYPE, FLOWER_TWO_PIN, COLOR_ORDER>(flowerTwo, FLOWER_TWO_LEDS);
  initFlowerColorDirection(petalsOne, FLOWER_ONE_LEDS, COLOR_NORMAL);
  initFlowerColorDirection(petalsTwo, FLOWER_TWO_LEDS, COLOR_INVERSE);
  // Set the colors for each flower. Comment out these two lines to set it to white. 
  FastLED.setBrightness(MASTER_BRIGHTNESS);
  FastLED.clear();
}

// Loop through and make the leds on each flower fade in and out at random times. 
void loop() {
  uint32_t reading = analogRead(POT_READ);
  reading = map(reading, 0, 1023, 0, 255);
  animate(flowerOne, petalsOne, FLOWER_ONE_LEDS, reading);
  animate(flowerTwo, petalsTwo, FLOWER_TWO_LEDS, reading);
  FastLED.show();
  delay(1);
}

// Takes an array of CRGBs and Petals and feeds the color of the petal to the CRGB.
void animate(CRGB* flower, Petal* petals, uint8_t ledCount, uint8_t potReading) {
  for (int i = 0; i < ledCount; ++i) {
    flower[i] = petals[i].getColor(potReading);
  }
}

// Takes an array of petals and sets the color using RGB values.
void initFlowerColorDirection(Petal *petals, uint8_t ledCount, bool direction) {
  for (int i = 0; i < ledCount; ++i) {
    petals[i].setColorDirection(direction);
  }
}