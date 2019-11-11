#include "d_Node.h"
#ifndef D_LIST_H
#define D_LIST_H

template <class T>
class dList
{
private:
	dNode<T> *head, *tail;

public:
	// Constructor
	dList();
	// Copy Constructor
	dList(const dList<T>& obj);
	// Destructor
	~dList();
	// Get head
	dNode<T> * getHead();
	// Insertion methods
	void append(T val);
	void prepend(T val);
	void putBefore(dNode<T> * targ, T val);
	// Removal method
	void removeNode(dNode<T> * targ);
	// Search
	dNode<T> * search(T val);
	// Print method
	void display();
	// Overloaded Operators
	void operator=(const dList<T>& obj);
};

#include "d_List.cpp"
#endif
