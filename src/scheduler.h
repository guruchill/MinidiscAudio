#ifndef SCHEDULER_H
#define SCHEDULER_H

#pragma once
#include <task.h>
#include "arduino.h"


#define MAX_TASKS 10

class scheduler
{
public:
    scheduler();
    ~scheduler();

private:
    task*       taskArray[MAX_TASKS];
    int         taskCount;
    long        lastActionTime =0;
    int         pollCycles = 0;
    


public: 
    int     addTask (task *TheTask);
    bool    setTaskState (int taskID, bool bDisabled);
    bool    setTaskFrequency (int taskID, int interval);
    void    process();

};

#endif