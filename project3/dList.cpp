// Justin Ventura (COSC220-003)
// Project 3 (modified 11/12/19)
// File: dList.cpp (Justin Ventura)

#include "dList.h"

// Default Constructor
template <typename T>
dList<T>::dList() : listSize(0)
{
    this->header = new dNode<T>;
    if (!header)
        std::cout << "FATAL ERROR: memory lack [header alloc]\n";
}

template <typename T>
dList<T>::dList(const dList<T> &obj)
{
    dNode<T> *curr = obj->header;
    while (curr->next != obj->header)
    {
        this->append(curr->data);
        curr = curr->next;
    }
}

void dList<T>::operator=(const dList<T> &obj)
{

}

template <typename T>
void dList<T>::append(T val)
{
    dNode<T> *newNode = new dNode<T>(val);
    if (!header)
    {
        std::cout << "ERROR: No header.\n";
        return;
    }
    else
    {
        dNode<T> *curr = header;

        while (curr->next != header)
        {
            curr = curr->next;
        }

        curr->next = newNode;
    }
}
