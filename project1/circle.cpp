/*
* circle.h
* Implementation of the Circle class.
* Author: Justin Ventura
* Created: September 18, 2019
* Current: September 19, 2019
*/

#include "circle.h"

Circle::Circle()
{
    radius = 1;
}
void Circle::setCenter(int x, int y)
{
    c.setX(x);
    c.setY(y);
}
float Circle::calcArea()
{
    return 3.14*(radius * radius);
}
bool Circle::canFit()
{
    // if the radius greater than 5, guarantee wont fit
    if (radius > 5) return false;
    // if the co-ordinates are outside of the plane, return false
    if ((c.getX() >= 10 || c.getX() <= -10) || (c.getY() >= 5 || c.getY() <= -5))
    { return false; }
    // checking to see if the shape will not fit in location
    if (c.getY() + radius > 5 || c.getY() - radius < -5) return false;
    if (c.getX() + radius > 10 || c.getX() - radius < -10) return false;
    return true;
}
