/*
Minidisc Audio Interface
Copyright (C) 2025 Tim Myers 

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <Arduino.h>
#include "OLEDHandler.h"
#include "scheduler.h"
#include <stdint.h>
#include "BluetoothA2DPSource.h"
#include <string.h>
#define c3_frequency  440.00
//3FFD0FE4
esp_bd_addr_t shokz{0x3f,0xFD, 0x0F, 0xE4};

#define DeviceName "Minidisc Player"
BluetoothA2DPSource a2dp_source;

// The supported audio codec in ESP32 A2DP is SBC. SBC audio stream is encoded
// from PCM data normally formatted as 44.1kHz sampling rate, two-channel 16-bit sample data
int32_t get_data_frames(Frame *frame, int32_t frame_count) 
{
    static float m_time = 0.0;
    float m_amplitude = 10000.0;  // -32,768 to 32,767
    float m_deltaTime = 1.0 / 44100.0;
    float m_phase = 0.0;
    float pi_2 = PI * 2.0;
    // fill the channel data
    for (int sample = 0; sample < frame_count; ++sample) {
        float angle = pi_2 * c3_frequency * m_time + m_phase;
        frame[sample].channel1 = m_amplitude * sin(angle);
        frame[sample].channel2 = frame[sample].channel1;
        m_time += m_deltaTime;
    }

    delay(1);
    return frame_count;
}

bool isValid(const char* ssid, esp_bd_addr_t address, int rssi)
{
  bool bRetVal = false; 
  Serial.print("available SSID: ");
  Serial.println(ssid);
  Serial.print("MAC Address: ");
  Serial.printf("%02x: \n", address);
  if (!a2dp_source.is_connected())
  {
    Serial.println("We're not connected. Try and connect now");
    a2dp_source.connect_to(address);
    bRetVal = true;
  }

   return bRetVal;
}



void button_handler(uint8_t id, bool isReleased){
  if (isReleased) {
    Serial.print("button id ");
    Serial.print(id);
    Serial.println(" released");
  }
}

void  setupBluetoothAudioTransmit() 
{
  Serial.printf("Bluetooth Audio setup");
  a2dp_source.set_task_core(1);                     //Move the bluetooth stack off to teh second core of the ESP32. 
  a2dp_source.set_volume(100);
  a2dp_source.set_ssid_callback(isValid);
  a2dp_source.set_auto_reconnect(false);
  a2dp_source.set_avrc_passthru_command_callback(button_handler);
  a2dp_source.set_data_callback_in_frames(get_data_frames); 
  a2dp_source.set_volume(30);
  a2dp_source.start("MyAudio");
  a2dp_source.connect_to(shokz);
}

scheduler *sched;
bool bRunning;

void setup() 
{
  Serial.begin(115200);
  Serial.println("Startup.........");
  sched = new scheduler(); 
  setupBluetoothAudioTransmit();
}


void loop() 
{

  try
  {
    //The scheduler should be considered interruptable, low priority and not accurate. If the system is busy,  it has the potential to miss 
    //Tasks. Audio shold be handled with an interrupt. 
    sched->process();  
    delay(1);

  }

  catch (const std::exception &e) 
  {
        Serial.println("Exception caught:");
        Serial.println(e.what());
    } 
    catch (...) 
    {
        Serial.println("Unknown exception caught.");
    }
    
}
  


