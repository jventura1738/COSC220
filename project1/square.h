/*
* square.h
* Definition (header) of the Square class.
* Author: Justin Ventura
* Created: September 18, 2019
* Current: September 19, 2019
*/

#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include "rect.h"

class Square : public Rectangle
{
    // private member of side
private:
    float side;
public:
    // Square
    // Constructor for square class
    // Parameter: none
    // Returns: nothing. just makes object
    // Preconditions: none
    // Postconditions: none
    Square(); // default
    Square(int s) : side(s), Rectangle(s,s) { }

    // ~Square
    // Destructor for square class
    // Parameter: none
    // Returns: nothing. just destroys object
    ~Square() { }

    // setter/getter methods
    void setSide(float s)
    { side = s; }
    float getSide() const
    { return side; }

    // calcArea
    // virtual function that calculates area of square object
    // Parameter: none, uses member data length and width
    // Returns: value of the sqaures area
    // Preconditions: side > 0
    // Postconditions: the area of the square object
    virtual float calcArea();

    // canFit
    // virtual function that checks if the square fits on the grid
    // Parameter: none, uses member data
    // Returns: bool value based on if the shape fits on the grid
    // Preconditions: side > 0
    // Postconditions: true if shape fits, false if it does not
    virtual bool canFit();
};

#endif
