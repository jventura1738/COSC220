//Justin Ventura COSC220-003
// LAB3: time24.cpp

#include "time24.h"
#include <iostream>

Time24::Time24()
{
  	hours = 0;
  	minutes = 0;
}
Time24::Time24(int h = 0, int m = 0): hours(h), minutes(m)
{
    normalizeTime();
}
void Time24::normalizeTime()
{
	int tempHours;
	tempHours = minutes/60;	//counts extra hours
	minutes %= 60;			//resets current minutes
	hours += tempHours;		//adds any new hours
	hours %= 24;
}
void Time24::readTime()
{
	int h, m;
  	char trash;
  	std::cout << "Enter time in the format -> HOUR:MIN ->";
  	std::cin >> h >> trash >> m;
  	hours = h;
  	minutes = m;
}
void Time24::writeTime()
{
    if (minutes%60 == 0)
    {
        std::cout << hours << ":0" << minutes << std::endl;
    }
    else if (minutes%10 == 0)
    {
        std::cout << hours << ":" << minutes << std::endl;
    }
    else if (minutes < 10)
    {
        std::cout << hours << ":0" << minutes << std::endl;
    }
    else
    {
        std::cout << hours << ":" << minutes << std::endl;
    }
	// writes time in format HR:MN
}
Time24 Time24::duration(const Time24& t)
{
    int startTime = hours * (60 + minutes);
	int endTime = t.hours * (60 + t.minutes);
    // returns an anonymous object that can be auto-formatted
	return Time24(0, (endTime - startTime));
}
void Time24::addTime(int m)
{
	minutes += m%60;		//add new minutes to current
	hours += m/60;			//add new hours to current
	normalizeTime();		//fixes the current time
}
int Time24::getHour()
{
	return hours;
}
int Time24::getMinute()
{
	return minutes;
}
