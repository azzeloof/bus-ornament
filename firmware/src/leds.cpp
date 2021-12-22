#include "leds.h"

uint8_t Level[NUM_LEDS];
uint8_t Order[NUM_LEDS];
uint8_t LogLevels[64] = { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,
                          1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  3,  3,
                          3,  4,  4,  4,  5,  5,  6,  7,  7,  8,  9, 10, 11, 12, 14, 15, 17,
                         18, 20, 23, 25, 28, 31, 34, 38, 42, 46, 51, 57, 63};

void initOrder()
{
    Order[0] = 0;
    Order[1] = 3;
    Order[2] = 1;
    Order[3] = 6;
    Order[4] = 2;
    Order[5] = 9;
    Order[6] = 4;
    Order[7] = 7;
    Order[8] = 8;
    Order[9] = 11;
    Order[10] = 5;
    Order[11] = 10;
}

void setupLeds()
{
  initOrder();
  clearLeds(); 
}

void setLed(uint8_t led, uint8_t level)
{
  if(led >= 0 && led < NUM_LEDS)
  {
    if(level < 0) level = 0;
    if(level > 63) level = 63;
    Level[Order[led]] = LogLevels[level];

  }
}

void setLedLog(uint8_t led, uint8_t level)
{
  if(led >= 0 && led < NUM_LEDS)
  {
    if(level < 0) level = 0;
    if(level > 63) level = 63;
    Level[Order[led]] = level;
  }
}

void clearLeds()
{
  for(int i = 0; i < NUM_LEDS; i++)
  {
    Level[Order[i]] = 0;
  }
}

void allOn()
{
  for(int i = 0; i < NUM_LEDS; i++)
  {
    Level[Order[i]] = 63;
  } 
}

int hold(uint32_t delayTime) {
    unsigned long startTime = millis();
    while((millis() - startTime) < delayTime) {
        if(checkButton() != 0) return 1;
    }
    return 0;
}

int fade(uint8_t led, uint8_t start, uint8_t end, uint32_t time) {
    uint8_t curLevel = start;
    uint8_t count = 0;
    uint8_t steps = abs(end - start);
    int32_t timeStep = time / steps;
    while (count < steps) {
        setLedLog(led, curLevel);
        if (hold(timeStep) != 0) return 1;
        curLevel += 1 - 2*(end < start);
        count ++;
    }
    setLed(led, end);
    return 0;
}

int crossfade(uint8_t led1, uint8_t led2, uint8_t start, uint8_t end, uint32_t time) {
    uint8_t curLevel = start;
    uint8_t count = 0;
    uint8_t steps = abs(end - start);
    int32_t timeStep = time / steps;
    while (count < steps) {
        setLedLog(led1, curLevel);
        setLedLog(led2, start - curLevel + end);
        if (hold(timeStep) != 0) return 1;
        curLevel += 1 - 2*(end < start);
        count ++;
    }
    setLed(led1, end);
    setLed(led2, start);
    return 0;
}