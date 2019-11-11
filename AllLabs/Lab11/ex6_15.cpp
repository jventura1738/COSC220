#include "time24.h"
#include <iostream>
#include <list>
#include <iterator>
#include <cstdlib>
#include <ctime>

int main ()
{
    srand(time(NULL));
    int num;
    std::cout << "enter an integer: ";
    std::cin >> num;

    std::list<int> intList;
    std::list<int>::iterator intIter;

    for (int i = 0; i < 10; i++)
    {
        int random_number = (std::rand() % 100);
        intList.push_front(random_number);
    }
    std::cout << "Numbers bigger than entry...\n";
    for (intIter = intList.begin(); intIter != intList.end(); intIter++)
    {
        if (*intIter > num)
            std::cout << *intIter << " ";
    }
    std::cout << "\n";

    std::list<Time24> tList, amList, pmList;
    std::list<Time24>::iterator iter;
    tList.push_back(Time24(8, 30));
    tList.push_back(Time24(13, 45));
    tList.push_back(Time24(7, 25));
    tList.push_back(Time24(11, 15));
    tList.push_back(Time24(18, 20));
    tList.push_back(Time24(21, 50));
    std::cout << "\ntList\n";
    for (iter = tList.begin(); iter != tList.end(); iter++)
    {
        std::cout << *iter << " ";
        if (iter->getHour() < 12)
            amList.push_back(*iter);
        else
            pmList.push_back(*iter);
    }
    std::cout << "\namList:\n";
    for (iter = amList.begin(); iter != amList.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << "\npmList:\n";
    for (iter = pmList.begin(); iter != pmList.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << "\n";

    return 0;
}
