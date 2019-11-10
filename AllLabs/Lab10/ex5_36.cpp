/*
  ex5_36.cpp
  Justin Ventura COSC220-003
*/

/********************  as provided on K drive *****************/

#include "d_rect.h"
#include "ex5_36Aux.h"

int main()
{
  using namespace std;

  rectangle ** rooms = getRoomArray();

  getRoomData(rooms);

  reportOnTotalArea(rooms);

  rectangle largePerim = largestPerimeter(rooms);

  reportOnLargest(largePerim);


  return 0;
}
