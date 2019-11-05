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
    int listcount;
    void remove_tail() 
    {
        nodeptr prev = head;
        while (prev->next->next != nullptr) 
        {
            prev = prev->next;
        }
        delete tail;
        tail = prev;
        prev->next = nullptr;
    }
    void remove_head() 
    {
        nodeptr temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }
public:

    List();
    List(const List& list);
    ~List();
    void prepend(T val);
    void append(T val);
    void remove_at(int pos);
    void print_list() const;
    int list_count() const;

};

#include "List.cpp"

#endif