/*
* square.h
* Definition (header) of the Circle class.
* Author: Justin Ventura
* Created: September 18, 2019
* Current: September 19, 2019
*/

#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include <iostream>

class Circle : public Shape
{
    //private member of radius for circle
private:
    float radius;
    // public members for circle class
public:
    // Circle
    // Constructor for Circle class
    // Parameter: none
    // Returns: nothing. just makes object
    // Preconditions: none
    // Postconditions: none
    Circle(); // default
    Circle(float r) : radius(r) { }

    // Circle
    // Destructor for Circle class
    // Parameter: none
    // Returns: nothing. just destroys object
    // Preconditions: none
    // Postconditions: none
    ~Circle() { }

    // setCenter
    // Sets center of the circle object
    // Parameter: X and Y co-ordinates
    // Returns: nothing. sets center co-ordinates
    // Preconditions: X and Y should be real numbers
    // Postconditions: sets center for the circle on grid
    void setCenter(int x, int y);

    // set/get radius methods
    void setRadius(float r)
    { radius = r; }
    // getter methods
    float getRadius() const
    { return radius;}

    // calcArea
    // Calculates area of the circle
    // Parameter: none, uses member data
    // Returns: float value for the area
    // Preconditions: radius should be defined
    // Postconditions: returns the area of this circle
    virtual float calcArea();

    // canFit
    // virtual function that checks if the circle fits on the grid
    // Parameter: none, uses member data
    // Returns: bool value based on if the shape fits on the grid
    // Preconditions: radius > 0
    // Postconditions: true if shape fits, false if it does not
    virtual bool canFit();
};

#endif
