#ifndef BSTNODE_H
#define BSTNODE_H

template <class T>
class BSTnode
{
public:
	T key;
	BSTnode * left;
	BSTnode * right;
	BSTnode * parent;

	// Default Constructor
	BSTnode() : key(T()), left(nullptr), right(nullptr),
				parent(nullptr) { }

	BSTnode(T& val = T(), BSTnode) : key() {}
};