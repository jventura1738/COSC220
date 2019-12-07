#ifndef TNODE_H
#define TNODE_H

template <class T>
class tnode {
public:
    T value;
    tnode<T> * left, right;

    // Constructor
    tnode(T val = T(), tnode<T>* l = nullptr, tnode<T>* r = nullptr) :
        value(val), left(l), right(r) {}
};

#endif
