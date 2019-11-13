// Justin Ventura (COSC220-003)
// Project 3 (modified 11/12/19)
// File: dNode.cpp (Justin Ventura)

#include "dNode.h"

// Copy Constructor
template <typename T>
dNode<T>::dNode(dNode<T>* obj)
{
    this->data = obj.data;
    this->next = obj->next;
    this->prev = obj->prev;
}

// Destructor
template <typename T>
dNode<T>::~dNode()
{
    // std::cout << "Node destroyed: " << this->data << "\n";
}

// Overloaded Assignment Operator
template <typename T>
dNode dNode<T>::operator=(dNode<T>* obj)
{
    this->data = obj.data;
    this->next = obj->next;
    this->prev = obj->prev;
}
