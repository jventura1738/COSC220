#include <iostream>
#include "tnode.h"
#include <queue>
// FIX QUEUE

// do inorder traversal of BT
void inorder(tnode *root)
{
    if (!root) return;
    if (root->left)
        inorder(root->left);
    std::cout << root->value << "\n";
    if (root->right)
        inorder(root->right);
}

// do preorder traversal of BT
void preorder(tnode *root)
{
    if (!root) return;
    if (root->left)
        preorder(root->left);
    std::cout << root->value << "\n";
    if (root->right)
        preorder(root->right);
}

// do postorder traversal of BT
void postorder(tnode* root)
{
    if (!root) return;
    if (root->left)
        postorder(root->left);
    std::cout << root->value << "\n";
    if (root->right)
        postorder(root->right);
}

// print BT in level order
void levelorder(tnode* root)
{
    if (!root)
    {
        std::cout << "Tree does not exist.\n";
        return;
    }
    queue <tnode*> q;
    tnode *curr = nullptr;
    q.push(root);
    // marks new level since root only has node
    q.push(nullptr);

    // loop over the tree.  use a queue to keep track
    // of tree level node values
    while (q.size() > 1)
    {
        // use curr to take this node into account.
        // pop the node since it is accounted for now
        curr = q.front();
        q.pop();
        if (!curr) // new level
        {
            q.push(nullptr);
            cout << "\n";
        }
        else // push the curr's children if any
        {
            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->left);

            std::cout << curr << " ";
        }
    }
}

// A utility function to insert a new node with given key in BT
tnode* insert(tnode* node, int key)
{
    // If the tree is empty, return a new node
    if (!node)
        return node = new tnode(key);

    // Otherwise, recur down the tree
    if (key < node->value)
        node->left = insert(node->left, key);
    else if (key > node->value)
        node->right = insert(node->right, key);

    // return the (unchanged) node pointer
    return node;
}

void deleteTree(tnode * root)
{
    if (!root)
    {
        std::cout << "Tree does not exist.\n";
        return;
    }
    if (root->left)
        deleteTree(root->left);
    if (root->right)
        deleteTree(root->right);
    delete root;
}

int main ()
{
    tnode *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print inorder traversal of the BST
    inorder(root);

    return 0;
}
