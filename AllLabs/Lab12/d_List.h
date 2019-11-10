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
	// Insertion methods
	void append(T val);
	void prepend(T val);
	void putAfter(dNode<T> * cand, T val);
	void putBefore(dNode<T> * cand, T val);
	// Removal methods
	/* void remove(); */
	// Search
	dNode<T> * search(T val);
	// Print method
	void display();
	// Overloaded Operators
	void operator=(const dList<T>& obj);
};

#include "d_List.cpp"
#endif