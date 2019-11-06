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
