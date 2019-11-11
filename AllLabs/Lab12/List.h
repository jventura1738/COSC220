// Justin Ventura
// COSC220-003
#ifndef LIST_H
#define LIST_H
#include "Node.h"

template <class T>
class List {
private:
    Node<T> *head;

public:
	// Constructor
    List();
    // Copy Constructor
    List(const List& list);
    // Destructor
    ~List();
    // Existence Check
    bool isInList(T key);
    // Insertion methods
    void prepend(T val);
    void append(T val);
    void insert(T val);
    // Removal method
    void remove(T val);
    // Print method
    void display();
    // List Count Getter
    int listSize();
    // Overloaded Assignment Operator
    void operator=(const List& list);
};

#include "List.cpp"
#endif
