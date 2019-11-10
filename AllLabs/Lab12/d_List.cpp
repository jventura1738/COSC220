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
void dList<T>::putAfter(dNode<T> * targ, T val)
{
	dNode<T> *newNode = new dNode<T>(val);
	newNode->prev = targ;
	newNode->next = targ->next;
	targ->next = newNode;
	if (!newNode->next)
		tail = newNode;
}

template <typename T>
void dList<T>::putBefore(dNode<T> * targ, T val)
{
	dNode<T> *newNode = new dNode<T>(val);
	newNode->next = targ;
	newNode->prev = targ->prev;
	targ->prev = newNode;
	if (!newNode->prev)
		head = newNode;
	std::cout << newNode->next->data << " " << newNode->prev->data << "\n";
}

/*
template <typename T>
void dList<T>::insert(T val)
{
	dNode<T> *newNode = new dNode<T>(val);
	if (!head)
	{
		std::cout << "--so, no head?\n";
		head = newNode;
		tail = newNode;
	}
	else
	{
		dNode<T> *curr = head;

		while (curr && curr->data < val)
			curr = curr->next;

		1 2 4
		c
		3 (val)

		dNode<T> *newNode = new dNode<T>(val);
		if (!curr->prev)
		{
			head = newNode;
			newNode->next = curr;
		}
		else
		{

		}

		newNode->next = curr;
		std::cout << "wack1\n";
		newNode->prev = curr->prev;
		std::cout << "wack2\n";
		curr->prev = newNode;
		std::cout << "wack3\n";

		if (!newNode->prev)
		{
			std::cout << "--new head\n";
			head = newNode;
		}
		else if (!newNode->next)
		{
			std::cout << "--new tail\n";
			tail = newNode;
		}
	}
}
*/

// Removal methods

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