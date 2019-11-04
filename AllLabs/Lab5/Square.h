// Justin Ventura COSC220-003
// LAB5: Square.h
#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle
{
public:
    Square(float s = 0.0) : Rectangle(s,s) {}
    void setSide(float s) { setWidth(s); setLength(s);}
    float getSide() {return getLength();}
};

#endif
