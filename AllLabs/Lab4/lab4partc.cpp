// Justin Ventura COSC220-003
// LAB4: lab4partc.cpp
// Driver and extra function for lab4

#include "complexx.h"
#include <iostream>

complexx functionZ(const complexx& z)
{
    complexx temp = ((z*z*z) - (3*(z*z)) + (4*z) - 2);
    return temp;
}

int main()
{
    complexx c1(2, 3);
    complexx c2(-1, 1);
    complexx c3(1, 1);
    complexx c4(1, -1);
    complexx c5(1, 0);
    std::cout << "f" << c1 << " = " << functionZ(c1) << "\n";
    std::cout << "f" << c2 << " = " << functionZ(c2) << "\n";
    std::cout << "f" << c3 << " = " << functionZ(c3) << "\n";
    std::cout << "f" << c4 << " = " << functionZ(c4) << "\n";
    std::cout << "f" << c5 << " = " << functionZ(c5) << "\n";

    return 0;
}
