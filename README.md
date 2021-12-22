# London Bus Ornament
 A PCB holiday ornament with lots of blinking LEDs!

## Hardware
The board consists of twelve reverse-mounted LEDs [charlieplexed](https://en.wikipedia.org/wiki/Charlieplexing) and hooked up to an ATtiny85. Each LED is individually addressable, even though only four of the ATtiny's pins are being used (Charlieplexing is magic)! The board also has a pushbutton for switching between modes. The ornament is powered via two CR2025 batteries which feed a 3.3V buck converter.

The design works as-is, but there's an issue. When the programmer is hooked up, it needs to be set to not power the PCB. If it does power the boar,d it will immediatley fry the buck converter. To get around this, I cut the VCC trace to the ICSP and connected that pin to the unused pin of the power switch via a bodged wire. 

## Firmware
The ATtiny is programmed using the PlatformIO framework. Before programming, you need to write an Arduino bootloader to the chip using the Arduino IDE. When burning the bootloader, here are the settings we used:

+ Chip: "ATtiny85" (from the ATtiny Core board library)
+ Clock: "8 MHz (internal)"
+ B.O.D: "B.O.D. Disabled"
+ Timer 1 Clock: "CPU"
+ LTO (1.6.11+ only): "Disabled"

The code is adapted from the wonderful work of David Johnson-Davies, published at http://www.technoblogy.com/show?2H0K.

To program the chips, we used SparkFun's [Pocket AVR Programmer](https://www.sparkfun.com/products/9825), but you should be able to use any programmer compatibe with the ATtiny85 (or just use an Arduino Uno!).

## Version History
Release 1.0 will represent the bus ornaments as we initially made and distributed them. Once it is released, maybe we'll improve some stuff (but any hardware improvements will be untested).

## Warning
Electricity creates heat, and excess heat around something like a Christmas tree can cause big problems. Use at your own risk! The designs here have only been minimally tested and are absolutley not guarenteed to be safe.
