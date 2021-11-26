#include "randomAnimation.h"

void randomProgram(uint32_t holdTime) {
    srand(millis());
    uint8_t randLed = rand() % 12;
    if (fade(randLed, 0, 63, holdTime/2) != 0) return;
    if (hold(holdTime) != 0) return;
    if (fade(randLed, 63, 0, holdTime/2) != 0) return;
}