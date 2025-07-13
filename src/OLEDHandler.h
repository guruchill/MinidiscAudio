#ifndef OLEDHANDLER_H
#define OLEDHANDLER_H
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <exception>

#pragma once

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

class OLEDHandler
{
public:
    OLEDHandler(int SCL, int SDL, int xMax, int yMax);
    ~OLEDHandler();
    bool init();
    bool drawString (int x, int y, String text);

private:
    int pinSCL, pinSDA;
    int xMax, yMax; 
    bool initialized =false;

};

#endif