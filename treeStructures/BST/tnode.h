#ifndef TNODE_H
#define TNODE_H
#include <iostream>

class tnode {
public:
    int value;
    tnode * left;
    tnode * right;

    // Constructor
    tnode(int val = 0, tnode* l = nullptr, tnode* r = nullptr) :
        value(val), left(l), right(r) {}

    friend std::ostream& operator<<(std::ostream& ostr, tnode* curr);
};

#endif
