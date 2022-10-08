#include "Petal.h"
#include <FastLED.h>

// All the ranges used for the random fading in and out of the leds. 
#define RANDOM_LOW_RANGE random(10, 20)
#define RANDOM_HIGH_RANGE random(rangeLow+25, 255)
#define RANDOM_SPEED random(8, 15)


Petal::Petal() {
    // Randomize the variables to start.
    randomizeVariables();
}

void Petal::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    // These RGB values end up being the denominator on the RGB values in the returned CRGB.
    this->red = 255/red;
    this->green = 255/green;
    this->blue = 255/blue;
}

CRGB Petal::getColor(void) {
    brightness = incrementBrightness(brightness);
    // Divide in the RGB data members. So 255/255 is 1, so full brightness for that value.
    // And 1/255 is close enough to zero to cancel out that value.
    return CRGB(brightness/red, brightness/green, brightness/blue);
}

uint8_t Petal::incrementBrightness(uint8_t brightness) {
    // Increment the brightness when the value matches the speed.
    if (millis()-lastInc >= speed) {
        lastInc = millis();
        brightness += inc;
        if (brightness == rangeHigh) {
            inc = -1; // Start decreasing the value once we reach the high limit
        }
        if (brightness == rangeLow) {
            inc = 1; // Start increasing the value once we reach the low limit.
            randomizeVariables();
        }
    }
    return brightness;
}

void Petal::randomizeVariables(void) {
    rangeLow = RANDOM_LOW_RANGE;
    rangeHigh = RANDOM_HIGH_RANGE;
    speed = RANDOM_SPEED;
    brightness = rangeLow+1;
}