/*
  ThreeDimPt.h
  ThreeDimPt is a 3-dimensional point
*/

#ifndef THREEDIMPT_H
#define THREEDIMPT_H

#include <iostream>
#include <fstream>

using namespace std;

class ThreeDimPt
{
public:
  // Constructor for point at (0,0,0)
  ThreeDimPt();

  // Constructor for point at (x,y,z)
  ThreeDimPt(int x, int y, int z);

  // Mutators for x, y, and z
  void SetX(int x);
  void SetY(int y);
  void SetZ(int z);

  // Accessors for x, y, and z
  int GetX() const;
  int GetY() const;
  int GetZ() const;

  // Relational operators
  bool operator < (const ThreeDimPt & rhs) const;
  bool operator > (const ThreeDimPt & rhs) const;
  bool operator == (const ThreeDimPt & rhs) const;

 private:
  int x;
  int y;
  int z;
};

// stream insertion operator
ostream & operator << (ostream &, const ThreeDimPt & pt);

#endif 