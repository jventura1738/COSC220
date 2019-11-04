// Justin Ventura COSC220-003
// LAB5: Textbook.h
#include "Textbook.h"

void Textbook::describe()
{
    std::cout << "Page length: " << pageLength << ".\n";
    if (cover == soft) std::cout << "Cover: soft cover.\n";
    else std::cout << "Cover: hard cover.\n";
    std::cout << "Subject: " << subject << "\n";
}
