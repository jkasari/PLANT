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
    
        uint8_t brightness = 1;
        uint32_t lastInc = 0;
        int8_t inc = 1;
        uint8_t rangeHigh = 0;
        uint8_t rangeLow = 0;
        uint32_t speed = 0;
        uint8_t red = 255;
        uint8_t green = 255;
        uint8_t blue = 255;

        // Gives a uint8_t that is increment once in either direction.
        uint8_t incrementBrightness(uint8_t);

        void randomizeVariables(void);
};