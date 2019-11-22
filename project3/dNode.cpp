// Justin Ventura (COSC220-003)
// Project 3 (modified 11/12/19)
// File: dNode.cpp (Justin Ventura)
// Implementation for the Doubly
// Linked List Node.
// Created: 11/12/19.
#include <iostream>
#include "dNode.h"

// Copy Constructor
template <class T>
dNode<T>::dNode(dNode<T>* obj)
{
    this->next = obj->next;
    this->prev = obj->prev;
    this->data = obj->data;
}

// Destructor
template <typename T>
dNode<T>::~dNode()
{
    //std::cout << "Node destroyed: " << this->data << "\n";
}

// Overloaded Assignment Operator
template <typename T>
dNode<T> dNode<T>::operator=(dNode<T>* obj)
{
    this->data = obj->data;
    this->next = obj->next;
    this->prev = obj->prev;
}
