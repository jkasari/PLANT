#include <FastLED.h>
#define COLOR_COUNT 3;

// Petal keeps track of a single brightness variable and transitions it from bright to dim in a smooth fashion.
// It uses this variable to create a CRGB object that visually will fade in and out smoothly.
class Petal {

    public:

        Petal();

        // Petal defaults to all white, this takes in RGB values to set the desired color for the petal. 
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
        uint8_t red = 1; // These cannot equal zero!
        uint8_t green = 1; // Yes I know this is sketchy but this whole program is a doodle so suck it future me. 
        uint8_t blue = 1;

        // Gives a uint8_t that is increment once in either direction.
        uint8_t incrementBrightness(uint8_t);

        // Takes all the data members and randomizes them. This way no two cycles are the same. 
        void randomizeVariables(void);
};