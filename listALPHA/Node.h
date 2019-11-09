#ifndef NODE_H
#define NODE_H

template <class T>
class Node 
{
public:
	T data;
	Node<T> *next;
	// Def Constructor
	Node();
	// Constructor
	Node(T val);
	// Copy Constructor
	Node(const Node<T>& obj);
	// Destructor
	~Node();
	// overloaded assignment operator
	Node operator=(const Node<T>& obj);
};

#include "Node.cpp"
#endif