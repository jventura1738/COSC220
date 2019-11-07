/*
  ThreeDimPt.cpp
  Implementation of 3-dimensional point
*/

#include "ThreeDimPt.h"

#include <iostream>

using namespace std;

ThreeDimPt::ThreeDimPt()
{
  x = y = z = 0;
}

ThreeDimPt::ThreeDimPt(int xpos, int ypos, int zpos)
{
  x = xpos;
  y = ypos;
  z = zpos;
}

void ThreeDimPt::SetX(int xpos)
{
  x = xpos;
}

void ThreeDimPt::SetY(int ypos)
{
  y = ypos;
}

void ThreeDimPt::SetZ(int zpos)
{
  z = zpos;
}


int ThreeDimPt::GetX() const
{
  return x;
}

int ThreeDimPt::GetY() const
{
  return y;
}

int ThreeDimPt::GetZ() const
{
  return z;
}


bool ThreeDimPt::operator < (const ThreeDimPt & rhs) const
{
  int thisMag = x * x + y * y + z * z;
  int rhsMag  = rhs.x * rhs.x + rhs.y * rhs.y + rhs.z * rhs.z;
    
  return (thisMag < rhsMag);
}

bool ThreeDimPt::operator > (const ThreeDimPt & rhs) const
{
  return !((*this == rhs) || (*this < rhs));
}

bool ThreeDimPt::operator == (const ThreeDimPt & rhs) const
{
  return (x == rhs.x && y == rhs.y && z == rhs.z);
}

ostream & operator << (ostream & str, const ThreeDimPt & pt)
{
  str << '<';
  str << pt.GetX() << ',' << pt.GetY() << ',' << pt.GetZ();
  str << '>';
  return str;
}