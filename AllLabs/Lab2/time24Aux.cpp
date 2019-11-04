//Justin Ventura COSC220-003
// LAB2: time24Aux.cpp
#include "time24Aux.h"
#include "time24.h"

bool isLater(Time24& t1, Time24& t2)
{
    if ((t1.getHour() >= t2.getHour()) && (t1.getMinute() > t2.getMinute())) return true;
    else if((t1.getHour() > t2.getHour()) && (t1.getMinute() >= t2.getMinute())) return true;
    else return false;
}
