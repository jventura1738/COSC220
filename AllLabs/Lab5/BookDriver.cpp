// Justin Ventura COSC220-003
// LAB5: BookDriver.cpp
// test driver
#include "Book.h"
#include "Textbook.h"
#include <iostream>

void identify(Book b)
{ b.describe(); }
void identify(Book *b)
{ b->describe(); }
void identify(Textbook b)
{ b.describe(); }
void identify(Textbook *b)
{ b->describe(); }

int main()
{
    /*
    Textbook courseBook(hard, 950, "computer science");
    Book myDictionary(soft, 625);

    myDictionary.describe();
    courseBook.describe();
    */

    Book cookBook(hard, 150);
    Book *p;
    Textbook poetry(soft, 500, "English");
    Textbook *q;

    p = &cookBook;
    identify(cookBook);
    identify(p);

    std::cout << "\n";

    q = &poetry;
    identify(q);
    identify(poetry);

    std::cout << "\n";

    p = & poetry;
    identify(p);


    return 0;
}
