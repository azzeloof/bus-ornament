#pragma once

#include "Arduino.h"
#include "modeButton.h"

#define NUM_LEDS 12
#define MIN_LEVEL 0
#define MAX_LEVEL 63

extern uint8_t Level[NUM_LEDS];
extern uint8_t Order[NUM_LEDS];

void setupLeds();
void setLed(uint8_t led, uint8_t level);
void setLedLog(uint8_t led, uint8_t level);
void clearLeds();
void allOn();
int hold(uint32_t delayTime);
int fade(uint8_t led, uint8_t start, uint8_t end, uint32_t time);
int crossfade(uint8_t led1, uint8_t led2, uint8_t start, uint8_t end, uint32_t time);