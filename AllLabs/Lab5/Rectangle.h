// Justin Ventura COSC220-003
// LAB5: Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle
{
private:
    float length;
    float width;
public:
    Rectangle(float l = 0.0, float w = 0.0) : length(l), width(w) {}
    void setLength(float l) {length = l;}
    void setWidth(float w) {width = w;}
    float getLength() {return length;}
    float getWidth() {return width;}
    float getPerimeter();
    float getArea();
};

#endif
