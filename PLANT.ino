#include "Petal.h"
#include <FastLED.h>

#define FLOWER_ONE_LEDS 5
#define FLOWER_TWO_LEDS 3
#define FLOWER_ONE_PIN 6
#define FLOWER_TWO_PIN 7
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
#define MASTER_BRIGHTNESS 125

// Create the correct number of CRGB objects and Petal objects to feed them color. 
CRGB flowerOne[FLOWER_ONE_LEDS];
CRGB flowerTwo[FLOWER_TWO_LEDS];
Petal petalsOne[FLOWER_ONE_LEDS];
Petal petalsTwo[FLOWER_TWO_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, FLOWER_ONE_PIN, COLOR_ORDER>(flowerOne, FLOWER_ONE_LEDS);
  FastLED.addLeds<LED_TYPE, FLOWER_TWO_PIN, COLOR_ORDER>(flowerTwo, FLOWER_TWO_LEDS);
  // Set the colors for each flower. Comment out these two lines to set it to white. 
  initFlowerColor(petalsOne, FLOWER_ONE_LEDS, 150, 70, 1); // These cannot be set to zero!!
  initFlowerColor(petalsTwo, FLOWER_TWO_LEDS, 70, 20, 150); // Once again, I know how dumb that is and probably will think about fixing it one day. :w
  
  FastLED.setBrightness(MASTER_BRIGHTNESS);
  FastLED.clear();
}

// Loop through and make the leds on each flower fade in and out at random times. 
void loop() {
  animate(flowerOne, petalsOne, FLOWER_ONE_LEDS);
  animate(flowerTwo, petalsTwo, FLOWER_TWO_LEDS);
  FastLED.show();
  delay(1);
}

// Takes an array of CRGBs and Petals and feeds the color of the petal to the CRGB.
void animate(CRGB* flower, Petal* petals, uint8_t ledCount) {
  for (int i = 0; i < ledCount; ++i) {
    flower[i] = petals[i].getColor();
  }
}

// Takes an array of petals and sets the color using RGB values.
void initFlowerColor(Petal *petals, uint8_t ledCount, uint8_t red, uint8_t green, uint8_t blue) {
  for (int i = 0; i < ledCount; ++i) {
    petals[i].setColor(red, green, blue);
  }
}