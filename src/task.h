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

#ifndef TASK_H
#define TASK_H

#pragma once

class task
{
public:
    task();
    ~task();
    void setCallback (void* cbfn);
    void* getCallback ();
    int getPeriod();
    void setPeriod(int Period);
    bool isEnabled();
    void Enable(bool enabled);


private:
    void* callback;
    int period;
    bool bEnabled;

public:


};

#endif