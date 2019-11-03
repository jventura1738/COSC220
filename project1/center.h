/*
* center.h
* Definition (header) of the Center class.
* Author: Justin Ventura
* Created: September 18, 2019
* Current: September 19, 2019
*/

#ifndef CENTER_H
#define CENTER_H
#include <iostream>

/* this class is a composition of the shape class
and all derived classes from class Shape.
*/

class Center
{
    // private so that no one can manipulate
private:
    int X, Y; // variables for x and y co-ordinates
public:
    // Center
    // Constructor for center class
    // Parameter: x and y are the co-ordinates for center
    // Returns: nothing. just makes object
    // Preconditions: x and y must be on the 20x10 x-y plane
    // Postconditions: object is created with X and Y co-ordinates
    Center(); // default
    Center(int x = 0, int y = 0) : X(x), Y(y) {}

    // ~Center
    // Destructor for center class
    // Parameter: none
    // Returns: nothing. just destroys object
    ~Center() { }
    
    // getter methods
    int getX() const
    { return X; }
    int getY() const
    { return Y; }
    // setter methods
    void setX(int x)
    { X = x; }
    void setY(int y)
    { Y = y; }

    // operator<< overload
    // Friend operator overloader for the << operator on a center object
    // Parameter: ostream object reference and Center object reference
    // Returns: ostream object
    // Preconditions: (x,y) must be on the 20x10 x-y plane
    // Postconditions: returns os object in form (x,y)
    friend std::ostream& operator<<(std::ostream& os, const Center& c);
};

#endif
