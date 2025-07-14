#ifndef BTAUDIOSENDER_H
#define BTAUDIOSENDER_H

#pragma once
#include <stdint.h>

class BTAudioSender
{
public:
    BTAudioSender();
    ~BTAudioSender();
    int32_t get_sound_data(uint8_t *data, int32_t byteCount);
    void setup();

private:

};

#endif