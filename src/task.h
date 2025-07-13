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