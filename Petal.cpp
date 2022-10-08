#include "Petal.h"
#include <FastLED.h>

Petal::Petal() {
    randomizeVariables();
}

void Petal::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    this->red /= red;
    this->green /= green;
    this->blue /= blue;
}

CRGB Petal::getColor(void) {
    brightness = incrementBrightness(brightness);
    return CRGB(brightness/red, brightness/green, brightness/blue);
}

uint8_t Petal::incrementBrightness(uint8_t brightness) {
    if (millis()-lastInc >= speed) {
        lastInc = millis();
        brightness += inc;
        if (brightness == rangeHigh) {
            inc = -1;
        }
        if (brightness == rangeLow) {
            inc = 1;
            randomizeVariables();
        }
    }
    return brightness;
}

void Petal::randomizeVariables(void) {
    rangeLow = random(20, 30);
    rangeHigh = random(rangeLow+25, 255);
    speed = random8(5);
    brightness = rangeLow+1;
}