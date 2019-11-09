// Justin Ventura
// COSC220-003
#include "Node.h"
#include <iostream>

// Def Constructor
template <class T>
Node<T>::Node()
{
	next = nullptr;
}

// Constructor
template <typename T>
Node<T>::Node(T val)
{
	data = val;
	next = nullptr;
}
// Copy Constructor
template <class T>
Node<T>::Node(const Node<T>& obj)
{
	data = obj.data;
	next = nullptr;
}
// Destructor
template <class T>
Node<T>::~Node()
{
	//std::cout << "\nNode Destroyed: " << data << "\n";
}
// overloaded assignment operator
template <class T>
Node<T> Node<T>::operator=(const Node<T>& obj)
{
	data = obj.data;
	next = obj->next;
}
