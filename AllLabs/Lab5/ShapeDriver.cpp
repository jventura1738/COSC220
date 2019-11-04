// Justin Ventura COSC220-003
// LAB5: ShapeDriver.cpp
// test driver

#include "Rectangle.h"
#include "Square.h"
#include <iostream>

int main()
{
    float side;
    std::cout << "Please enter the side of a square: ";
    std::cin >> side;

    Square S(side);

    std::cout << "Area of entered square: " << S.getArea() << "\n";
    std::cout << "Perimeter: " << S.getPerimeter() << "\n";
    std::cout << "Doubling side of square...\n";
    S.setLength(S.getLength()*2);
    S.setWidth(S.getWidth()*2);
    std::cout << "Area of doubled square: " << S.getArea() << "\n";
    std::cout << "Perimeter: " << S.getPerimeter() << "\n";

    return 0;
}
