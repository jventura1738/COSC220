//Justin Ventura COSC220-003
// LAB3: time12.h

#ifndef TIME12_H
#define TIME12_H
#include "time24.h"

// specifies clock time units
enum timeUnit {AM, PM};

// maintains clock time
class Time12
{
private:
    Time24 t;
        // store time in 24-hour format

    Time24 convert12To24(int h=12, int m=0, timeUnit tunit = AM);
        // build t from standard time
public:
    Time12(int h=12, int m=0, timeUnit tunit = AM);
        // initialize time24 data member t

    void addTime(int m);
        // add m minutes to update current time

    void readTime();
    void writeTime();
      // I/O member functions use format HH:MM: AM (PM)

    // OVERLOADED OPERATORS
    Time12 operator =(Time12& t);
    friend Time12 operator +(Time12& t, int m);
};

#endif
