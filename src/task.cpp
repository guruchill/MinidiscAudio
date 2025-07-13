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