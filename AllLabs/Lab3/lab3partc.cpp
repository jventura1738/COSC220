//Justin Ventura COSC220-003
// LAB3: lab3partc.cpp

#include <iostream>
#include "time12.h"

int main()
{
    Time12 t1;
    std::cout << "\n" << "Enter time in which the job begins ";
    t1.readTime();
    t1.addTime(320); // 5 hours and 20 minutes later
    std::cout << "Job will finish at ";
    t1.writeTime();
    std::cout << std::endl;

    return 0;
}
