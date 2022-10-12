#include "Petal.h"
#include <FastLED.h>

// All the ranges used for the random fading in and out of the leds. 
#define RANDOM_LOW_RANGE random(50, 70)
#define RANDOM_HIGH_RANGE random(rangeLow+25, 255)
#define RANDOM_SPEED random(8, 15)
#define SATURATION 200


Petal::Petal() {
    // Randomize the variables to start.
    randomizeVariables();
}

void Petal::setColorDirection(bool direction) {
    // These RGB values end up being the denominator on the RGB values in the returned CRGB.
    this->direction = direction;
}

// Calls the increment function and returns a color based on that petals color direction.
// This makes is so the each plant changes different colors from each other.
CHSV Petal::getColor(uint8_t potReading) {
    brightness = incrementBrightness(brightness);
    if (direction) {
        return CHSV(potReading, SATURATION, brightness);
    } else {
        return CHSV(255-potReading, SATURATION, brightness);
    }
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