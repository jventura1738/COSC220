// Justin Ventura COSC220-003
// LAB5: Textbook.h
#ifndef TEXTBOOK_H
#define TEXTBOOK_H
#include "Book.h"
#include <string>

class Textbook : public Book
{
private:
    std::string subject;
public:
    Textbook() : Book(soft, 0), subject("") {}
    Textbook(bookCover c, int pl, std::string sub) : Book(c, pl), subject(sub) {}
    virtual void describe();
};

#endif
