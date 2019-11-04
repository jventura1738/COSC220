//Justin Ventura COSC220-003
// LAB3: time24.h

#ifndef TIME_H
#define TIME_H

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
};

#endif
