/*
* square.cpp
* Implementation of the Square class.
* Author: Justin Ventura
* Created: September 18, 2019
* Current: September 19, 2019
*/

#include "square.h"

Square::Square() : Rectangle(1,1)
{
    side = 1;
}
float Square::calcArea()
{
    return side*side;
}
bool Square::canFit()
{
    // early condition checks (grid is 20x10 = 200, but square max is 100 units)
    if (side/2 > 5) return false; // if side/2 > 5, area would be too big for grid
    // if the co-ordinates are outside of the plane, return false
    if ((c.getX() >= 10 || c.getX() <= -10) || (c.getY() >= 5 || c.getY() <= -5))
    { return false; }
    if (c.getX() + side/2 > 10 || c.getX() - side/2 < -10) return false;
    if (c.getY() + side/2 > 5 || c.getY() - side/2 < -5) return false;
    return true;
}
