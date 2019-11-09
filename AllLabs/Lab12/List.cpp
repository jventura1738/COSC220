// Justin Ventura
// COSC220-003
#include "List.h"
#include "Node.h"

template <typename T>
List<T>::List() 
{
	//std::cout << "\nConstructing Linked List.\n";
	head = nullptr;
}

template <typename T>
List<T>::List(const List& list) 
{
	//std::cout << "\nCopy Constructing Linked List.\n";
	if (!list.head)
		return;
	else
	{
		Node<T> *curr = list.head;
		while (curr)
		{
			this->append(curr->data);
			curr = curr->next;
		}
	}
}

template <typename T>
List<T>::~List() 
{
	//std::cout << "\nDestroying Linked List\n";
	Node<T> *prev;
	Node<T> *curr = head;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		delete prev;
	}
}

template <typename T>
bool List<T>::isInList(T key)
{
	if (!head)
		return false;
	Node<T> *curr = head;
	while (curr)
	{
		if (curr->data == key)
			return true;
		curr = curr->next;
	}
	return false;
}

template <typename T>
void List<T>::prepend(T val)
{
	Node<T> *newNode = new Node<T>(val);
	if (!head)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

template <typename T>
void List<T>::append(T val)
{
	Node<T> *newNode = new Node<T>(val);
	newNode->next = nullptr;
	if (!head)
	{
		head = newNode;
	}
	else
	{
		Node<T> *curr = head;	

		while(curr->next)
			curr = curr->next;

		curr->next = newNode;
	}
}

template <typename T>
void List<T>::insert(T val)
{
	Node<T> *newNode = new Node<T>(val);
	newNode->next = nullptr;
	if (!head)
	{
		head = newNode;
	}
	else
	{
		Node<T> *curr = head;
		Node<T> *prev;

		while (curr != nullptr && curr->data < val)
		{
			prev = curr;
			curr = curr->next;
		}

		if (prev == nullptr)
		{
			head = newNode;
			newNode->next = curr;
		}
		else
		{
			prev->next = newNode;
			newNode->next = curr;
		}
	}
}

template <typename T>
void List<T>::remove(T val)
{
	Node<T> *curr = head;
	Node<T> *prev;
	if (!head)
		return;
	else if (head->data == val)
	{
		curr = head->next;
		delete head;
		head = curr;
	}
	else
	{
		while (curr != nullptr && curr->data != val)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr)
		{
			prev->next = curr->next;
			delete curr;
		}
	}
}

template <typename T>
void List<T>::display()
{
	Node<T> *curr = head;
	if (!curr)
		std::cerr << "\n--Empty List--\n";
	else
	{
		while (curr)
		{
			std::cout << curr->data << " ";
			curr = curr->next;
		}
		std::cout << "\n";
	}
}

template <typename T>
int List<T>::listSize()
{
	int count = 0;
	Node<T> *curr = head;
	while (curr != nullptr)
	{
		count++;
		curr = curr->next;
	}
	return count;
}

template <typename T>
void List<T>::operator=(const List& list)
{
	//std::cout << "\nAssigning Linked List.\n";
	if (!list.head)
		return;
	else
	{
		Node<T> *curr = list.head;
		while (curr)
		{
			this->append(curr->data);
			curr = curr->next;
		}
	}
}
