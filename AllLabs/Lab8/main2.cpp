// Justin Ventura COSC220-003
// LAB8: main2.cpp
// MAIN FOR LAB8
#include "isPal.h"
#include <iostream>

int main()
{
    std::string test = "hannah";
    bool flag = isPal(test, 0, 5);
    unsigned short result = (flag) ? 1 : 0;
    std::cout << result << "\n";
    // prints 1 since palindrome

    test = "jack goff";
    flag = isPal(test, 0, 3);
    result = (flag) ? 1 : 0;
    std::cout << result << "\n";
    // prints 0 since not palindrome

    test = "racecar";
    flag = isPal(test, 0, 6);
    result = (flag) ? 1 : 0;
    std::cout << result << "\n";
    // prints 1 since palindrome

    test = "justin";
    flag = isPal(test, 0, 5);
    result = (flag) ? 1 : 0;
    std::cout << result << "\n";
    // prints 0 since not palindrome

    test = "taco cat";
    flag = isPal(test, 0, 7);
    result = (flag) ? 1 : 0;
    std::cout << result << "\n";
    // prints 0 since not palindrome

    return 0;
}
