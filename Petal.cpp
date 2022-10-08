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
        countArr[i] += 1;
        rgbArr[i] = equate(countArr[i]);
    }
    return CRGB(rgbArr[0]/red, rgbArr[1]/green, rgbArr[2]/blue);
}

uint8_t Petal::equate(uint32_t count) {

    EVERY_N_MILLISECONDS(recalcTime) {
        randomizeVariables();
    }
    
    //return ( (rangeHigh-rangeLow) * (triwave8( (count+distance)/freq ) / 256 ) ) + rangeLow;
    return rangeHigh*(triwave8(count+distance)/freq)/256+rangeLow;
}

void Petal::randomizeVariables(void) {
    freq = random(8, 12);
    rangeLow = random(20, 40);
    rangeHigh = random(rangeLow+25, 255)-rangeLow;
    distance = random8(0, 50);
    recalcTime = random8()*20;
}