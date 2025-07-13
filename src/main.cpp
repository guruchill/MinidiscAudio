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



scheduler *sched;
bool bRunning;

void setup() 
{

  sched = new scheduler(); 

}


void loop() 
{
  Serial.begin(115200);
  try
  {
    //The scheduler should be considered interruptable, low priority and not accurate. If the system is busy,  it has the potential to miss 
    //Tasks. Audio shold be handled with an interrupt. 
    sched->process();  
  }

  catch (const std::exception &e) 
  {
        Serial.println("Exception caught:");
        Serial.println(e.what());
    } catch (...) {
        Serial.println("Unknown exception caught.");
    }
}
  