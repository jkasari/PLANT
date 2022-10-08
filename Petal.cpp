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
    uint8_t rgbArr[3];
    for (int i = 0; i < 3; ++i) {
        rgbArr[i] = equate();
    }
    return CRGB(rgbArr[0]/red, rgbArr[1]/green, rgbArr[2]/blue);
}

uint8_t Petal::equate() {
    EVERY_N_MILLISECONDS(speed) {
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