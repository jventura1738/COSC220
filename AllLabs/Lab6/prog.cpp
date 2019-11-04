/******************************************
 * prog.cpp
 *
 * Main function definition
 *
 ******************************************/

#include "foo.h"
#include <iostream>

int main ()
{
  using std::cout;
  using std::endl;

  Foo f(2);

  cout << "x is " << f.getX()
       << '\t'
       << "y is " << f.getY()
       << endl;

  return 0;
}
