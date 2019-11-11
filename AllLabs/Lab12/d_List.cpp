// Justin Ventura
// COSC220-003 Lab12
#include <iostream>
#include "d_List.h"

// Constructor
template <class T>
dList<T>::dList()
{
	this->head = nullptr;
	this->tail = nullptr;
}

// Copy Constructor
template <class T>
dList<T>::dList(const dList<T>& obj)
{
	if (!obj.head)
		return;
	else
	{
		dNode<T> *curr = obj.head;
		while (curr)
		{
			this->append(curr->data);
			curr = curr->next;
		}
	}
}

// Destructor
template <class T>
dList<T>::~dList()
{
	std::cout << "destroying list...\n";
	dNode<T> *curr = head;
	while (curr->next)
	{
		curr = curr->next;
		delete curr->prev;
	}
	delete curr;
}

// Insertion methods
template <typename T>
void dList<T>::append(T val)
{
	dNode<T> *newNode = new dNode<T>(val);
	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

template <typename T>
void dList<T>::prepend(T val)
{
	dNode<T> *newNode = new dNode<T>(val);
	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

template <typename T>
void dList<T>::putBefore(dNode<T> * targ, T val)
{
	dNode<T> *newNode = new dNode<T>(val);
	newNode->next = targ;
	newNode->prev = targ->prev;
	targ->prev->next = newNode;
	targ->prev = newNode;
	if (!newNode->prev)
		head = newNode;
}

// Removal method
template <typename T>
void dList<T>::removeNode(dNode<T> * targ)
{
	if (head == tail)
	{
		delete head;
		delete tail;
	}
	else if (targ == head)
	{
		head = head->next;
		delete head->prev;
	}
	else if (targ == tail)
	{
		std::cout << "big brain\n";
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
	else
	{
		targ->prev->next = targ->next;
		targ->next->prev = targ->prev;
		delete targ;
	}
}

template <typename T>
dNode<T> * dList<T>::getHead()
{
	return this->head;
}

// Search method
template <typename T>
dNode<T> * dList<T>::search(T val)
{
	if (!head)
		return nullptr;
	else
	{
		dNode<T> *curr = head;
		while (curr && curr->data != val)
		{
			curr = curr->next;
		}
		// returns nullptr if not found
		return curr;
	}
}

// Print method
template <class T>
void dList<T>::display()
{
	dNode<T> *curr = head;
	while (curr)
	{
		std::cout << curr->data << " ";
		curr = curr->next;
	}
	std::cout << "\n";
}

// Overloaded Assignment Operator
template <class T>
void dList<T>::operator=(const dList<T>& obj)
{
	if (!obj.head)
		return;
	else
	{
		dNode<T> *curr = obj.head;
		while (curr)
		{
			this->append(curr->data);
			curr = curr->next;
		}
	}
}
