/*
  d_rect.cpp
  Ford/Topp "Data Structures with C++ using STL, 2nd edition"
  Implementation of the d_rect class originally contained in
  d_rect.h
  Thomas Anastasio
  Created: November 5, 2002
  Current: November 5, 2002
*/

#include "d_rect.h"

  // constructor. initializes length and width
rectangle::rectangle(double len, double wid)
  : length(len), width(wid)
{}


double rectangle::area() const
{
  return length * width;
}

double rectangle::perimeter() const
{
  return 2 * (length + width);
}

void rectangle::setSides(double len, double wid)
{
  length = len;
  width = wid;
}


double rectangle::getLength() const
{
  return length;
}

double rectangle::getWidth() const
{
  return width;
}
