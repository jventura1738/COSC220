//Justin Ventura COSC220-003
// LAB3: time12.h

#include "time12.h"
#include <iostream>
#include <string>
#include <iomanip>

Time12::Time12(int h, int m, timeUnit tunit)
{
    t = convert12To24(h, m, tunit);
}

Time24 Time12::convert12To24(int h, int m, timeUnit tunit)
{
    if (tunit == AM && h == 12)
    {
        return Time24((h - 12), m);
    }
    else if ((tunit == PM && h == 12) || tunit == AM)
    {
        return Time24(h, m);
    }
    else
    {
        return Time24((h + 12), m);
    }
}

void Time12::addTime(int m)
{
    t.addTime(m);
}

void Time12::readTime()
{
    int h, m;
  	char trash;
    char temp[2];
  	std::cout << "format -> (05:30PM or 11:05AM) -> ";
  	std::cin >> h >> trash >> m >> temp[0] >> temp[1];

    if (temp[0] == 'A' && temp[1] == 'M')
    {
        m = (m + (h*60));
        t.addTime(m);
    }
    else if (temp[0] == 'P' && temp[1] == 'M')
    {
        h += 12;
        m = (m + (h*60));
        t.addTime(m);
    }
    else
    {
        std::cout << "Invalid Input\n";
    }
}
void Time12::writeTime()
{
    int h, m;
    char temp[2] = {'A','M'};
    h = t.getHour();
    m = t.getMinute();

    if (h > 12)
    {
        temp[0] = 'P';
        temp[1] = 'M';
        h -= 12;
    }
    else if (h == 12)
    {
        temp[0] = 'P';
        temp[1] = 'M';
    }
    else if (h == 0)
    {
        h = 12;
    }

    if (m%60 == 0 || m < 10) std::cout << h << ":0" << m << temp[0] << temp[1] << std::endl;
    else if (m%10 == 0) std::cout << h << ":" << m << temp[0] << temp[1] << std::endl;
    else std::cout << h << ":" << m << temp[0] << temp[1] << std::endl;
}

Time12 Time12::operator =(Time12& tObj)
{
    int m = ((tObj.t.getHour())*60 + tObj.t.getMinute());
    addTime(m);
    return *this;
}

Time12 operator+ (Time12& t, int m)
{
    Time12 temp = t;
    temp.addTime(m);
    return temp;
}
