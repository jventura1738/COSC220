/*
* shape.cpp
* Implementation of the Shape class
* Author: Justin Ventura
* Created: September 18, 2019
* Current: September 19, 2019
*/

#include "shape.h"

void Shape::moveCenter(int x, int y)
{
    c.setX(x);
    c.setY(y);
}
void Shape::displayStats()
{
    std::cout << "    Area of the shape: " << calcArea() << " units squared.\n";
    std::cout << "         Center of shape: " << c << std::endl;
}
