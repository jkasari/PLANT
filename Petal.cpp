#include "Petal.h"
#include <FastLED.h>

Petal::Petal() {
    freq = random8(1, 7);
}

CRGB Petal::getColor(void) {
    uint8_t rgbArr[3];
    for (int i = 0; i < 3; ++i) {
        countArr[i] += 1;
        rgbArr[i] = equate(countArr[i]);
    }
    return CRGB(rgbArr[0], rgbArr[1], rgbArr[2]);
}

uint8_t Petal::equate(uint32_t count) {
    return triwave8(count/freq);
}