#include "List.h"

template <typename T>
List<T>::List() 
{
	listcount = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
List<T>::List(const List& list) 
{
	listcount = 0;
	head = nullptr;
	tail = nullptr;
	if (list.list_count() == 0) 
	{
		return;
	} 
	else 
	{
		int temp;
		nodeptr cursor = list.head;
		for (int i = 1; i <= list.list_count(); i++) 
		{
			temp = cursor->data;
			append(temp);
			cursor = cursor->next;
		}
		cursor = nullptr;
	}
}

template <typename T>
List<T>::~List() 
{
	while (listcount >= 1) 
	{
		remove_at(listcount);
	}
	head = nullptr;
	tail = nullptr;
}

template <typename T>
void List<T>::prepend(T val) 
{
	nodeptr temp = new Node;
	temp->data = val;
	temp->next = head;
	head = temp;
	listcount++;
}

template <typename T>
void List<T>::append(T val) 
{
	nodeptr temp = new Node;
	temp->data = val;
	temp->next = nullptr;
	if (head == NULL) 
	{
		head = temp;
		tail = temp;
		temp = nullptr;
	} 
	else 
	{
		tail->next = temp;
		tail = temp;
	}
	listcount++;
}

template <typename T>
void List<T>::remove_at(int pos) 
{
	if (pos <= 0) 
	{
		std::cerr << "Error: not valid position.\n";
	}
	else if (head == nullptr) 
	{
		std::cerr << "\nList is empty.\n";
		return;
	}
	else if (pos == 1) 
	{
		listcount--;
		remove_head();
		return;
	}
	else if (pos == listcount) 
	{
		listcount--;
		remove_tail();
		return;
	}
	else 
	{
		listcount--;
		nodeptr curr = head;
		nodeptr prev = head;
		nodeptr temp;
		for (int i = 1; i < pos; i++) 
		{
			if (i + 1 == pos)
			{
				prev = curr;
			}
			curr = curr->next;
		}
		temp = curr;
		curr = curr->next;
		delete temp;
		prev->next = curr;
	}
}

template <typename T>
void List<T>::print_list() const 
{
	nodeptr temp = head;
	while (temp != NULL) 
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << "\n";
}

template <typename T>
int List<T>::list_count() const 
{
	return listcount;
}