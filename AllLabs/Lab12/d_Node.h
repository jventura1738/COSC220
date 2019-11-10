#ifndef D_NODE_H
#define D_NODE_H

template <class T>
class dNode 
{
public:
	// data member
	T data;
	// pointers for traversal
	dNode<T> *next;
	dNode<T> *prev;
	// utilities
	dNode();
	dNode(T val);
	dNode(dNode<T>* obj);
	~dNode();
	dNode operator=(dNode<T>* obj);
};

#include "d_Node.cpp"
#endif