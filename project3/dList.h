// Justin Ventura (COSC220-003)
// Project 3 (modified 11/12/19)
// File: dList.h (Justin Ventura)
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

    ~dList();

    // Overloaded Assignment Operator
    void operator=(const dList<T> &obj);

    // Prepend Node (After Header)
    void prepend(T &val);

    // Append Node (Before Header)
    void append(T &val);

    // Remove Node
    void removeNode(dNode<T> *node);

    // Get Header
    dNode<T> * getHeader()
    { return this->header; }

    void setHeader(dNode<T> * head)
    { this->header = head; }

    // Return the size of List
    int size()
    { return listSize; }

    // Check for Empty List
    bool isEmpty()
    { return (listSize == 0) ? true : false; }

    // Unchain the header [Remove Circularity].
    void unchain();

    // Rechain the header [Fixes Circularity].
    void chain();

    // Display List
    void printOrder();

    // Diplay List (Reverse)
    void printReverse();
};

#include "dList.cpp"

#endif
