// Justin Ventura COSC220-003
// LAB4: lab4partb.cpp
// Driver for lab4

#include <iostream>
#include "complexx.h"

int main()
{
    complexx complex_number1;
    complexx complex_number2;
    complexx temp_complex;

    std::cout << "=============================================\n";
    std::cout << "Enter a complex number in the form: REAL IMAG";
    std::cout << "   -----> ";
    std::cin >> complex_number1;

    std::cout << "\n";

    std::cout << "Enter a complex number in the form: REAL IMAG";
    std::cout << "   -----> ";
    std::cin >> complex_number2;

    std::cout << "\n";

    std::cout << "Doing arithmetic operations on numbers...\n";
    std::cout << "=============================================\n\n";

    // add two complex numbers
    std::cout << "Result from adding first to second: \n";
    temp_complex = complex_number1 + complex_number2;
    std::cout << temp_complex << std::endl;

    std::cout << "\n... subtraction: \n";
    temp_complex = complex_number1 - complex_number2;
    std::cout << temp_complex << std::endl;

    std::cout << "\n... multiplication: \n";
    temp_complex = complex_number1 * complex_number2;
    std::cout << temp_complex << std::endl;

    std::cout << "\n... division: \n";
    temp_complex = complex_number1 / complex_number2;
    std::cout << temp_complex << std::endl;

    std::cout << "\n";

    if (complex_number1 == complex_number2)
    {
        std::cout << complex_number1 << " is equal to "
                  << complex_number2;
    }
    else
    {
        std::cout << complex_number1 << " is not equal to "
                  << complex_number2 << std::endl;
    }

    return 0;
}
