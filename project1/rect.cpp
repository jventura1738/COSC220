/*
* rect.cpp
* Implementation of the Rectangle class.
* Author: Justin Ventura
* Created: September 18, 2019
* Current: September 19, 2019
*/

#include "rect.h"

void Rectangle::setDimensions(float l, float w)
{
    length = l;
    width = w;
}
void Rectangle::setCenter(int x, int y)
{
    c.setX(x);
    c.setY(y);
}
float Rectangle::calcArea()
{
    return length*width;
}
bool Rectangle::canFit()
{
    // early condition checks (grid is 20x10 = 200)
    if (length*width > 200) return false;
    // if the co-ordinates are outside of the plane, return false
    if ((c.getX() >= 10 || c.getX() <= -10) || (c.getY() >= 5 || c.getY() <= -5))
    { return false; }
    // checking to see if the shape will not fit in location
    if (c.getX() + length/2 > 10 || c.getX() - length/2 < -10) return false;
    if (c.getY() + width/2 > 5 || c.getY() - width/2 < -5) return false;
    return true;
}
