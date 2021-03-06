// Justin Ventura (COSC220-003)
// Project 3 (modified 11/12/19)
// File: dNode.h (Justin Ventura)
// Class for Doubly Linked List Node.
// Created: 11/12/19.
#ifndef DNODE_H
#define DNODE_H

template <class T>
class dNode
{
public:
    // Data Member of type T
	T data;

	// Pointers for Traversal
	dNode<T> *next;
	dNode<T> *prev;

	// ---UTILITY FUNCTIONS---

    // Default Constructor
	dNode() : next(this), prev(this) {}

    // Constructor
	dNode(T & val) : data(&val), next(this), prev(this) {}

    // Copy Constructor
	dNode(dNode<T>* obj);

    // Destructor
	~dNode();

    // Overloaded Assignment Operator
	dNode operator=(dNode<T>* obj);
};

#include "dNode.cpp"

#endif
