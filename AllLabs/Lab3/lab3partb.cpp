//Justin Ventura COSC220-003
// LAB3: lab3partb.cpp

#include <iostream>
#include "time12.h"

int main()
{
    timeUnit tUnit1, tUnit2;
    Time12 NYCTime(12, 0, AM);
    Time12 GERMANY = NYCTime + 360;
    std::cout << "New York City Time (New Years): ";
    NYCTime.writeTime();
    std::cout << "Frankfurt, Germany equivalent: ";
    GERMANY.writeTime();
    return 0;
}
