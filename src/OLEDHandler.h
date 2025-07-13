#ifndef OLEDHANDLER_H
#define OLEDHANDLER_H

#pragma once

class OLEDHandler
{
public:
    OLEDHandler(int SCL, int SDL);
    ~OLEDHandler();
    bool init();

private:
    int pinSCL;
    int pinSDA;


};

#endif