#include "scrollingSequentialAnimation.h"

void scrollingSequentialProgram(uint8_t nLeds, uint32_t cycleTime) {
    uint32_t fadeTime = cycleTime / 4;
    uint32_t holdTime = cycleTime - fadeTime;
    uint8_t nextLed;
    for (uint8_t led=0; led<NUM_LEDS; led++) {
        if (led == NUM_LEDS - nLeds) {
            nextLed = 0;
        } else {
            nextLed = led + nLeds;
        }
        if (crossfade(led, nextLed, MAX_LEVEL, MIN_LEVEL, fadeTime) != 0) return;
        if (hold(holdTime) != 0) return;
    }
    return;
}