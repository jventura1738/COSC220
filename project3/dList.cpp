// Justin Ventura (COSC220-003)
// Project 3 (modified 11/12/19)
// File: dList.cpp (Justin Ventura)

#include "dList.h"
#include <iostream>

// Default Constructor
template <typename T>
dList<T>::dList() : listSize(0)
{
    std::cout << "header created. CONS\n";
    this->header = new dNode<T>;
    if (!header)
        std::cout << "--FATAL ERROR: memory lack [header alloc]\n";
}

// Copy Constructor
template <typename T>
dList<T>::dList(const dList<T> &obj)
{
    dNode<T> *curr = obj.header;
    while (curr->next != obj.header)
    {
        this->append(curr->data);
        curr = curr->next;
    }
}

// Destructor
template <typename T>
dList<T>::~dList()
{
    std::cout << "Destroying List.\n";
    while (header->next != header)
        removeNode(header->next);

    listSize = 0;

    delete header;
}

// Overloaded AO
template <typename T>
void dList<T>::operator=(const dList<T> &obj)
{
    dNode<T> *curr = obj.header;
    while (curr->next != obj.header)
    {
        this->append(curr->data);
        curr = curr->next;
    }
}

// [PRIVATE] Insert before given dNode
template <typename T>
dNode<T> * dList<T>::putBefore(dNode<T> *curr, T * val)
{
    dNode<T> *newNode = new dNode<T>(val);
    if (!newNode)
    {
        std::cout << "--ERROR: memory lack [dNode]\n";
        return nullptr;
    }

    newNode->prev = curr->prev;
    newNode->next = curr;
    curr->prev->next = newNode;
    curr->prev = newNode;

    return newNode;
}

// Prepend value to the front
template <typename T>
void dList<T>::prepend(T *val)
{
    putBefore(header->next, val);
    listSize++;
}

// Append value to the front
template <typename T>
void dList<T>::append(T *val)
{
    putBefore(header, val);
    listSize++;
}

// Remove a given node
template <typename T>
void dList<T>::removeNode(dNode<T> *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;
    listSize--;
}

// Print data in order
template <typename T>
void dList<T>::printOrder()
{
    dNode<T> *curr = header->next;
    while (curr != header)
    {
        std::cout << curr->data;
        curr = curr->next;
    }
}

// Print data in reverse order
template <typename T>
void dList<T>::printReverse()
{
    dNode<T> *curr = header->prev;
    while (curr!= header)
    {
        std::cout << curr->data;
        curr = curr->prev;
    }
}