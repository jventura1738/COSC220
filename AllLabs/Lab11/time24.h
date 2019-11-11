//Justin Ventura COSC220-003
// LAB7: time24.h

#ifndef TIME_H
#define TIME_H
#include <iostream>

class Time24
{
private:
    int hours;
    int minutes;

public:
    Time24();
    Time24(int,int);
    void readTime();
    void writeTime();
    Time24 duration(const Time24&);
    void addTime(int);
    int getHour();
    int getMinute();
    void normalizeTime();

    friend Time24 operator+(const Time24& lhs, const Time24& rhs);
    friend std::ostream& operator<< (std::ostream& ostr, const Time24& x);
    Time24 operator +=(const Time24& rhs);
};

#endif
