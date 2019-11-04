
/********************************************
 * foo.h
 * Declaration of Foo class
 *
 ********************************************/

#ifndef FOO_H
#define FOO_H 

#include "bar.h"

class Foo
{
 public:
  Foo(int);

  int getX() const;
  float getY() const;

 private:
  int x;
  Bar b;  // a real doll
};

#endif
