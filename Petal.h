#include <FastLED.h>

// Petal keeps track of a single brightness variable and transitions it from bright to dim in a smooth fashion.
// It uses this variable to create a CRGB object that visually will fade in and out smoothly.
class Petal {

    public:

        Petal();

        // Takes a bool to set the direction of the color travel as the pot is turned
        void setColorDirection(bool);

        // Returns a CRGB color incremented by 1 each time called.  
        CHSV getColor(uint8_t);

    private:
    
        uint8_t brightness = 1;
        uint32_t lastInc = 0;
        int8_t inc = 1;
        uint8_t rangeHigh = 0;
        uint8_t rangeLow = 0;
        uint32_t speed = 0;
        bool direction = true;
        // Gives a uint8_t that is increment once in either direction.
        uint8_t incrementBrightness(uint8_t);

        // Takes all the data members and randomizes them. This way no two cycles are the same. 
        void randomizeVariables(void);
};