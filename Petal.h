#include <FastLED.h>
#define COLOR_COUNT 3;

// Keeps track and mutates three uint8_ts and returns a CRGB built with these variables.
class Petal {

    public:

        Petal();

        void setColor(uint8_t, uint8_t, uint8_t);

        // Returns a CRGB color incremented by 1 each time called.  
        CRGB getColor(void);

    private:
    
        uint8_t brightness = 150;
        uint8_t freq = 1;
        uint8_t rangeHigh = 0;
        uint8_t rangeLow = 0;
        uint8_t distance = 0;
        uint32_t recalcTime = 0;
        uint32_t countArr[3];
        uint8_t red = 255;
        uint8_t green = 255;
        uint8_t blue = 255;

        uint8_t equate(uint32_t);

        void randomizeVariables(void);
};