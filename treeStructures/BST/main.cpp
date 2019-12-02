#include <iostream>

struct BSTnode
{
    int data;
    struct BSTnode *left, *right;
};

// create a new node
struct BSTnode *newNode(int val)
{
    struct BSTnode *temp =  new BSTnode;
    temp->data = val;
    temp->left = temp->right = nullptr;
    return temp;
}

// do inorder traversal of BST
void inorder(struct BSTnode *root)
{
    if (root->left)
        inorder(root->left);
    std::cout << root->data << "\n";
    if (root->right)
        inorder(root->right);
}

// A utility function to insert a new node with given key in BST
struct BSTnode* insert(struct BSTnode* node, int key)
{
    // If the tree is empty, return a new node
    if (!node) return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    // return the (unchanged) node pointer
    return node;
}

int main ()
{
    struct BSTnode *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print inoder traversal of the BST
    inorder(root);

    return 0;
}
