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

#include "scheduler.h"
#include <Arduino.h>

scheduler::scheduler()
{
    taskCount = 0;
    for (int taskCount=0; taskCount<MAX_TASKS; taskCount++)
    {
      taskArray[taskCount]=nullptr;
    }
}

int scheduler::addTask (task* theTask)
{
  bool retVal=-1;

  if ( taskCount >= MAX_TASKS)
  {
    retVal=-1;
  }
  else
  {
    taskArray[taskCount]=theTask;
    taskCount +=1;
  }
  return retVal;
}

scheduler::~scheduler()
{
  for ( int task = 0; task < taskCount; taskCount++)
  {
    delete taskArray[task];
  }
}


void scheduler::process()
{

  long timeNow;
  timeNow = millis();
  
  if ( timeNow > (lastActionTime+1000))    // 1 second
  {
    pollCycles++;
    

    for (int iTask =0; iTask<MAX_TASKS; iTask++ )
    {
      if ((taskArray[iTask]->getCallback()!=nullptr)&&(taskArray[iTask]->isEnabled())&&(taskArray[iTask]->getPeriod()%pollCycles==0))
      {
        Serial.printf("Executing task with index %d", iTask);
        //Execute the task
        (*taskArray[iTask]).getCallback();  
      }
    }

    lastActionTime = millis();
  }
}

