#include <FastLED.h>
#define COLOR_COUNT 3;

// Keeps track and mutates three uint8_ts and returns a CRGB built with these variables.
class Petal {

    public:

        Petal();

        // Returns a CRGB color incremented by 1 each time called.  
        CRGB getColor(void);

    private:
    
        uint8_t brightness = 0;
        uint8_t freq = 9;
        uint8_t rangeHigh = 256;
        uint8_t rangeLow = 0;
        uint32_t countArr[3];

        uint8_t equate(uint32_t);
};