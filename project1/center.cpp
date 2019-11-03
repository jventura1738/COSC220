/*
* center.cpp
* Implementation of the center class.
* Author: Justin Ventura
* Created: September 18, 2019
* Current: September 19, 2019
*/
#include "center.h"

Center::Center() : X(0), Y(0) { } // default constructor
std::ostream& operator<<(std::ostream& os, const Center &c)
{
    os << "(" << c.getX() << ", " << c.getY() << ")";
    return os;
}
