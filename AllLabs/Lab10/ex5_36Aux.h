/*
  ex5_36Aux.h
  Justin Ventura COSC220-003
*/

/********************  as provided on K drive *****************/

#ifndef EX5_36AUX_H
#define EX5_36AUX_H

#include "d_rect.h"

// getRoomArray
// Constructs and returns an array of pointers to rectangle.
// The number of rooms is obtained by prompting and reading from the
// keyboard.
// Each pointer points to a dynamically allocated rectangle object.
// The actual array size is one more than the number of rooms.  The last
// entry of the array is a NULL pointer.  This can be used as a sentinel
// for end of array.
rectangle ** getRoomArray();

// getRoomData
// PreCondition:  rooms is a properly constructed array of pointers
// to rectangle (see documentation for getRoomArray)
// Prompts for length and width of each room (i.e. rectangle) and gets those
// data from the keyboard.
// PostCondition: each room has received its length and width from the keyboard
void getRoomData(rectangle ** rooms);

// getTotalArea
// Returns the total area of the rooms on the array of pointers to rectangle.
// Precondition: the array is properly constructed (see documentation for getRoomArray)
double getTotalArea(rectangle ** rooms);

// largestPerimeter
// Returns a copy of the room that has the largest perimeter of all the rooms.
// Precondition: rooms is properly constructed (see documentation for getRoomArray)
rectangle largestPerimeter(rectangle ** rooms);

// reportOnLargest
// Prints a report on largeRoom.
// The report gives the perimeter of largeRoom as well as its dimensions.
void reportOnLargest(rectangle & largeRoom);

// reportOnTotalArea
// Prints a report on the total area in rooms.
// Precondition: rooms is properly constructed (see documentation for getRoomArray)
void reportOnTotalArea(rectangle ** rooms);

#endif
