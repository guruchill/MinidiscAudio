#include "scheduler.h"

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
    
    if ( pollCycles % 5 == 0)               // 5 seconds
    {
      
     
    }
    
    if ( pollCycles %10 == 0)               // 10 seconds
    {
     
    }

    if ( pollCycles % 30 == 0)              // 30 seconds
    {
      
    }

    if ( pollCycles %45 == 0)               // 45 seconds
    {
      
    }

    if ( pollCycles % 60 == 0)              // 1 minute
    {
      pollCycles = 0;

      
    }

    lastActionTime = millis();
  }
}

