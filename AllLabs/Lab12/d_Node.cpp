// Justin Ventura
// COSC220-003 Lab12
#include <iostream>
#include "d_Node.h"

// Def Constructor
template <class T>
dNode<T>::dNode()
{
	this->next = nullptr;
	this->prev = nullptr;
}

// Constructor
template <typename T>
dNode<T>::dNode(T val)
{
	this->data = val;
	this->next = nullptr;
	this->prev = nullptr;
}

// Copy Constructor
template <class T>
dNode<T>::dNode(dNode<T>* obj)
{
	this->data = obj->data;
	this->next = obj->next;
	this->prev = obj->prev;
}

// Destructor
template <class T>
dNode<T>::~dNode()
{
	//std::cout << "--dNode destroyed: " << this->data << "\n";
}

// Assignment Operator Overload
template <class T>
dNode<T> dNode<T>::operator=(dNode<T>* obj)
{
	this->data = obj->data;
	this->next = obj->next;
	this->prev = obj->prev;
}
