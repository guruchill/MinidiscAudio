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

#ifndef SCHEDULER_H
#define SCHEDULER_H

#pragma once
#include <task.h>


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