#ifndef TIMER_H
#define TIMER_H
#include <time.h>
#include <iostream>

class Timer
{
private:
    clock_t start_time, end_time;
public:
    Timer();
    void start_timer();
    void end_timer();
    double get_time();
    void reset_time();
    void display_time();
};

#endif
