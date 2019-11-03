/*
* shapeTryRecenter.h
* Definition (header) of the shapeTryRecenter helper functions
* Author: Justin Ventura
* Created: September 20, 2019
* Current: September 20, 2019
*/

#ifndef SHAPETRYRECENTER_H
#define SHAPETRYRECENTER_H
#include "shape.h"
#include "circle.h"
#include "square.h"
#include "rect.h"
// three overloaded bool functions that will check if the
// given shape can be recentered to fit a 20x10 x-y grid

// canBeRecentered (Circle overload)
// Overloaded function to check if a circle can be recentered on the 20x10 grid
// Parameter: A Circle object reference (address)
// Returns: a boolean value for if the circle can be recentered on grid
// Preconditions: circle should not fit grid before calling, but it can handle
// Postconditions: determines whether the given circle can be recentered on grid
bool canBeRecentered(Circle &C1);

// canBeRecentered (Square overload)
// Overloaded function to check if a square can be recentered on the 20x10 grid
// Parameter: A Square object reference (address)
// Returns: a boolean value for if the square can be recentered on grid
// Preconditions: square should not fit grid before calling, but it can handle
// Postconditions: determines whether the given square can be recentered on grid
bool canBeRecentered(Square &S1);

// canBeRecentered (Rectangle overload)
// Overloaded function to check if a rect can be recentered on the 20x10 grid
// Parameter: A Rectangle object reference (address)
// Returns: a boolean value for if the rect can be recentered on grid
// Preconditions: rect should not fit grid before calling, but it can handle
// Postconditions: determines whether the given rect can be recentered on grid
bool canBeRecentered(Rectangle &R1);

#endif
