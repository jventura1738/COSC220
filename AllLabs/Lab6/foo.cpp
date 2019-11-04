
/*********************************************
 * foo.cpp
 *
 * Implementation of Foo class
 *
 *********************************************/

#include "foo.h"

Foo::Foo(int a) : x(a)
{}

int Foo::getX() const
{
  return x;
}

float Foo::getY() const
{
  return b.getY();
}
