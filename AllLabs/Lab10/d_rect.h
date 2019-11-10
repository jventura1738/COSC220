/*
  d_rect.h
  Ford/Topp "Data Structures with C++ using STL, 2nd edition"
  Modified November 5, 2002 by T. Anastasio:
    -- to explicitly scope std namespace entities as std::entity
  rather than have global using namespace std
    -- to put the implementation in d_rect.cpp
*/

#ifndef RECTANGLE_CLASS
#define RECTANGLE_CLASS

// maintains measurement properties of a rectangle
class rectangle
{
 public:
  // constructor. initializes length and width
  rectangle(double len = 0.0, double wid  = 0.0);

  // return the area (length * width)
  double area() const;

  // return the perimeter (2 * (length + width))
  double perimeter() const;

  // change the dimensions of the rectangle to len and wid
  void setSides(double len, double wid);

  // return the length of the rectangle
  double getLength() const;

  // return the width of the rectangle
  double getWidth() const;

 private:
  double length;
  double width;
};

#endif   // RECTANGLE_CLASS
