/*
* shape.h
* Definition (header) of the shape
* Author: Justin Ventura
* Created: September 18, 2019
* Current: September 19, 2019
*/

#ifndef SHAPE_H
#define SHAPE_H
#include "center.h"
#include <iostream>

/* this is the abstract base class that will be
used as a template for all shapes: rectangle, square
and circle.
*/
class Shape
{
    // these members are public so that derived classes
    // can access these and call them.
public:
    // Shape
    // Contructor for Shape class
    // Parameter: none
    // Returns: nothing. just creates object
    // Preconditions: none
    // Postconditions: none
    Shape() : c(0,0) { }

    // Shape
    // Destructor for Shape class
    // Parameter: none
    // Returns: nothing. just destroys object
    // Preconditions: none
    // Postconditions: none
    ~Shape() { }

    // center data
    Center c;

    // moveCenter
    // Moves the center of a shape on the grid
    // Parameter: x and y for co-ordinates center object
    // Returns: nothing. just updates this shapes center object
    // Preconditions: 10 >= x >= -10, 5 >= x >= -5
    // Postconditions: X and Y co-ordinates of the center object updated
    void moveCenter(int x, int y);

    // displayStats
    // Displays the shapes area and center formatted (x, y).
    // Parameter: none, just prints
    // Returns: nothing. just prints
    // Preconditions: Area and center must be defined
    // Postconditions: prints the area's shape and center
    virtual void displayStats();

    // pure virtual function to calculate shape area
    virtual float calcArea() = 0;

    //pure virtual function to see whether shape fits on grid
    virtual bool canFit() = 0;
};

#endif
