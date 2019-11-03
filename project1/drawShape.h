/*
* drawShape.h
* Definition (header) of the drawShape helper functions
* Author: Justin Ventura
* Created: September 21, 2019
* Current: September 21, 2019
*/

#ifndef DRAWSHAPE_H
#define DRAWSHAPE_H
#include "shape.h"
#include "circle.h"
#include "square.h"
#include "rect.h"

// drawShape (Circle overload)
// Draws the shape to the console
// Parameter: A const Circle object reference (address)
// Returns: draws shape on console
// Preconditions: circle should fit the grid (20x10)
// Postconditions: displays the given shape on console
void drawShape(const Circle &C1);

// drawShape (Square overload)
// Draws the shape to the console
// Parameter: A const Square object reference (address)
// Returns: draws shape on console
// Preconditions: square should fit the grid
// Postconditions: displays the given shape on console
void drawShape(const Square &S1);

// drawShape (Rectangle overload)
// Draws the shape to the console
// Parameter: A const Rectangle object reference (address)
// Returns: draws shape on console
// Preconditions: rect should fit the grid
// Postconditions: displays the given shape on console
void drawShape(const Rectangle &R1);

#endif
