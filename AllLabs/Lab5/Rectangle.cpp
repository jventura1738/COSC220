// Justin Ventura COSC220-003
// LAB5: Rectangle.cpp

#include "Rectangle.h"
#include "Square.h"

float Rectangle::getPerimeter()
{
    return 2*(length + width);
}
float Rectangle::getArea()
{
    return (length*width);
}
