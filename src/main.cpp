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
  