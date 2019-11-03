/*
* rect.h
* Definition (header) of the Rectangle class.
* Author: Justin Ventura
* Created: September 18, 2019
* Current: September 19, 2019
*/

#ifndef RECT_H
#define RECT_H
#include <iostream>
#include "shape.h"

class Rectangle : public Shape
{
    // private members so outside can access
private:
    float length, width; // members of a rectangle

    // public members of rectangle class
public:
    // Rectangle
    // Constructor for rectangle class
    // Parameter: l and w for length and width of rectangle respectively
    // Returns: nothing. just makes object
    // Preconditions: l and w must be greater than 0
    // Postconditions: object is created with length and width
    Rectangle() : length(1), width(1) { } // default
    Rectangle(float l, float w) : length(l), width(w) { }

    // ~Rectangle
    // Destructor for rectangle class
    // Parameter: none
    // Returns: nothing. just destroys object
    ~Rectangle() {}

    // setDimensions
    // Sets dimensions of the rectangle object
    // Parameter: l and w for length and width of rectangle respectively
    // Returns: nothing. just updates object
    // Preconditions: l and w must be greater than 0
    // Postconditions: length and width of rectangle object updated
    void setDimensions(float l, float w);

    // setCenter
    // Sets the center co-ordinates for this rectangles
    // Parameter: x and y for co-ordinates of rectangle center object
    // Returns: nothing. just updates this rectangles center object
    // Preconditions: 10 >= x >= -10, 5 >= x >= -5
    // Postconditions: X and Y co-ordinates of rectangle center object updated
    void setCenter(int x, int y);

    // setter/getter methods
    void setLength(float l)
    { length = l; }
    void setWidth(float w)
    { width = w; }
    float getLength() const
    { return length; }
    float getWidth() const
    { return width; }

    // calcArea
    // virtual function that calculates area of Rectangle object
    // Parameter: none, uses member data length and width
    // Returns: value of the rectangles area
    // Preconditions: length > 0 and width > 0
    // Postconditions: the area of the rectangle object
    virtual float calcArea();

    // canFit
    // virtual function that checks if the rectanlge fits on the grid
    // Parameter: none, uses member data
    // Returns: bool value based on if the shape fits on the grid
    // Preconditions: length > 0 and width > 0
    // Postconditions: true if shape fits, false if it does not
    virtual bool canFit();
};

#endif
