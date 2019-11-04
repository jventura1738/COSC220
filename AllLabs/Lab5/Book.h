// Justin Ventura COSC220-003
// LAB5: Book.h
#ifndef BOOK_H
#define BOOK_H
#include <iostream>

enum bookCover {hard = 0, soft};

class Book
{
protected:
    bookCover cover;
    int pageLength;
public:
    Book() : cover(soft), pageLength(0) {} // default constructor
    Book(bookCover c, int pl) : cover(c), pageLength(pl) {}
    virtual void describe();
};

#endif
