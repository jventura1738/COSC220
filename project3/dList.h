// Justin Ventura (COSC220-003)
// Project 3 (modified 11/12/19)
// File: dList.h (Justin Ventura)
#ifndef DLIST_H
#define DLIST_H

template <class T>
class dList
{
private:

    // Sentinal Node
    dNode<T> *header;

    // List Count Size
    int listSize;

public:

    // Default Constructor
    dList();

    // Copy Constructor
    dList(const dList<T> &obj);

    // Overloaded Assignment Operator
    void operator=(const dList<T> &obj);

    // Append Node
    void append(T val);

    // Get Header
    dNode<T> getHeader()
    { return this->header; }

    // Display List
    void printOrder();

    // Diplay List (Reverse)
    void printRev();
}

#include "dList.cpp"

#endif
