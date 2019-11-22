// Justin Ventura (COSC220-003)
// Project 3 (modified 11/21/19)
// File: dList.h (Justin Ventura)
// *SPECIAL: extra methods.
// Created: 11/12/19.
#ifndef DLIST_H
#define DLIST_H
#include "dNode.h"

template <class T>
class dList
{
private:

    // Sentinal Node
    dNode<T> *header;

    // List Count Size
    int listSize;

    // Hidden Insert Method
    dNode<T> * putBefore(dNode<T> *curr, T & val);

public:

    // Default Constructor
    dList();

    // Copy Constructor
    dList(const dList<T> &obj);

    // Destructor
    ~dList();

    // Overloaded Assignment Operator
    void operator=(const dList<T> &obj);

    // Prepend Node (After Header)
    void prepend(T &val);

    // Append Node (Before Header)
    void append(T &val);

    // Remove Node
    // Give the Node to be Removed.
    void removeNode(dNode<T> *node);

    // Get Header
    // Returns Pointer to the Header.
    dNode<T> * getHeader()
    { return this->header; }

    // Set Header [*SPECIAL]
    // Used to Fix the Chaining which may have been
    // Modified After a Sort Was Performed.
    void setHeader(dNode<T> * head)
    { this->header = head; }

    // Return the Size of List
    int size()
    { return listSize; }

    // Check for Empty List
    bool isEmpty()
    { return (listSize == 0) ? true : false; }

    // Unchain the Header [Remove Circularity]
    // Used Before Sorting. [*SPECIAL]
    void unchain();

    // Rechain the Header [Fixes Circularity]
    // Used After Sorting. [*SPECIAL]
    void chain();

    // Display List
    void printOrder();

    // Diplay List (Reverse Order)
    void printReverse();
};

#include "dList.cpp"

#endif
