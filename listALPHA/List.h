#ifndef LIST_H
#define LIST_H

template <class T>
class List {
private:
    typedef struct Node
    {
        T data;
        Node* next;
    } *nodeptr;
    nodeptr head, tail; // pointers to front and rear
    
public:

    List();
    List(const List& list);
    ~List();
    

};

#include "List.cpp"

#endif