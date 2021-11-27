#include "randomAnimation.h"

void randomProgram(uint32_t cycleTime) {
    uint32_t fadeTime = cycleTime / 4;
    uint32_t holdTime = cycleTime - fadeTime;
    srand(millis());
    uint8_t randLed = (rand() + 1) % NUM_LEDS;
    if (fade(randLed, 0, 63, holdTime/2) != 0) return;
    if (hold(holdTime) != 0) return;
    if (fade(randLed, 63, 0, holdTime/2) != 0) return;
    return;
}