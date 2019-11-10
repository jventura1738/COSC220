// getRoomArray
// Constructs and returns an array of pointers to rectangle.
// The number of rooms is obtained by prompting and reading from the
// keyboard.
// Each pointer points to a dynamically allocated rectangle object.
// The actual array size is one more than the number of rooms.  The last
// entry of the array is a NULL pointer.  This can be used as a sentinel
// for end of array.
#include "ex5_36Aux.h"
#include <iostream>
rectangle ** getRoomArray()
{
    int n;
    std::cout << "Enter rooms: ";
    std::cin >> n;
    rectangle **rect = new rectangle*[n + 1];
    for (int i = 0; i < n; i++)
    {
        (rect[i]) = new rectangle;
    }
    rect[n + 1] = NULL;
    return rect;
}

// getRoomData
// PreCondition:  rooms is a properly constructed array of pointers
// to rectangle (see documentation for getRoomArray)
// Prompts for length and width of each room (i.e. rectangle) and gets those
// data from the keyboard.
// PostCondition: each room has received its length and width from the keyboard
void getRoomData(rectangle ** rooms)
{
    int i = 0;
    double length, width;
    while (rooms[i] != NULL)
    {
        std::cout << "Enter room dimensions l,w: ";
        std::cin >> length >> width;
        rooms[i]->setSides(length, width);
        i++;
    }
}

// getTotalArea
// Returns the total area of the rooms on the array of pointers to rectangle.
// Precondition: the array is properly constructed (see documentation for getRoomArray)
double getTotalArea(rectangle ** rooms)
{
    double total = 0;;
    int i = 0;
    while (rooms[i] != NULL)
    {
        total += rooms[i]->area();
        i++;
    }
    return total;
}

// largestPerimeter
// Returns a copy of the room that has the largest perimeter of all the rooms.
// Precondition: rooms is properly constructed (see documentation for getRoomArray)
rectangle largestPerimeter(rectangle ** rooms)
{
    int max = 0;
    int i = 0;
    while (rooms[i] != NULL)
    {
        if (rooms[i]->perimeter() > rooms[max]->perimeter())
            max = i;
        i++;
    }
    return *rooms[max];
}

// reportOnLargest
// Prints a report on largeRoom.
// The report gives the perimeter of largeRoom as well as its dimensions.
void reportOnLargest(rectangle & largeRoom)
{
    std::cout << "Largest room perimeter: " << largeRoom.perimeter();
    std::cout << "\nLargest room L/W: " << largeRoom.getLength() << " "
              << largeRoom.getWidth();
    std::cout << "\n";
}

// reportOnTotalArea
// Prints a report on the total area in rooms.
// Precondition: rooms is properly constructed (see documentation for getRoomArray)
void reportOnTotalArea(rectangle ** rooms)
{
    double total = getTotalArea(rooms);
    std::cout << "Total area from all rooms: " << total << "\n";
}
