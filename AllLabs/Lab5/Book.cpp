// Justin Ventura COSC220-003
// LAB5: Book.cpp
#include "Book.h"

void Book::describe()
{
    std::cout << "Page length: " << pageLength << ".\n";
    if (cover == soft) std::cout << "Cover: soft cover.\n";
    else std::cout << "Cover: hard cover.\n";
}
