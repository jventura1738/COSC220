//Justin Ventura COSC220-003
// LAB2: lab2TimeDriver.cpp
#include <iostream>
#include "time24.h"
#include "time24Aux.h"

int main()
{
    /*

    bool b;
    Time24 t1(9, 0);
    Time24 t2(17, 0);
    int m = 0;
    while (isLater(t1, t2) == false)
    {
        std::cout << "Enter an increment in minutes: ";
        std::cin >> m;
        t1.addTime(m);
        std::cout << "Time: ";
        t1.writeTime();
    }

    */
    Time24 t;

    t.addTime(840);

    t.writeTime();

}
