// Justin Ventura (COSC220-003)
// Project 3 (modified 11/12/19)
// File: dNode.h (Justin Ventura)
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
	dNode() : next(nullptr), prev(nullptr) {}

    // Constructor
	dNode(T val) : data(val), next(nullptr), prev(nullptr) {}

    // Copy Constructor
	dNode(dNode<T>* obj);

    // Destructor
	~dNode();

    // Overloaded Assignment Operator
	dNode operator=(dNode<T>* obj);
};

#include "dNode.cpp"

#endif
