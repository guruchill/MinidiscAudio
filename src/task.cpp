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

#include "task.h"

task::task()
{
  callback=nullptr;
  bEnabled=false;
  period=1000; //Default to a 1s task. 
}

task::~task()
{

}

void task::setCallback ( void* cbfn)
{
  callback = cbfn;

}

void* task::getCallback()
{
  return callback;
}

 int task::getPeriod()
 {
  return period;
 }

 void task::setPeriod(int Period)
{
  period=Period;
}

bool task::isEnabled()
{
  return bEnabled;
}
    
void task::Enable(bool enabled)
{

  bEnabled=enabled;

}