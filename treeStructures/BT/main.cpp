#include <iostream>
#include "tnode.h"
#include <queue>

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
    std::cout << root->value << "\n";
    if (root->left)
        preorder(root->left);
    if (root->right)
        preorder(root->right);
}

// do postorder traversal of BT
void postorder(tnode* root)
{
    if (!root) return;
    if (root->left)
        postorder(root->left);
    if (root->right)
        postorder(root->right);
    std::cout << root->value << "\n";
}

// print BT in level order
void levelorder(tnode* root)
{
    if (!root)
    {
        std::cout << "Tree does not exist.\n";
        return;
    }

    std::queue <tnode*> q;
    tnode *curr;

    // marks new level since root level (0) only has node
    q.push(root);
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
            std::cout << "\n";
        }
        else // push the curr's children if any
        {
            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);

            std::cout << curr << " ";
        }
    }
}

// A utility function to insert a new node with given key in BT
tnode* insert(tnode* root, int key)
{
    // If the tree is empty, return a new root
    if (!root)
        return root = new tnode(key);

    // Otherwise, recur down the tree
    if (key < root->value)
        root->left = insert(root->left, key);
    else if (key > root->value)
        root->right = insert(root->right, key);

    // return the (unchanged) root pointer
    return root;
}

// count leaf nodes for BT given root
int countleaf(tnode* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    else
    {
        return (countleaf(root->left) +
                countleaf(root->right));
    }
}

// get depth of BT
int depth(tnode* root)
{
    int left, right, total;
    if (!root)
        return -1;
    else
    {
        left = depth(root->left);
        right = depth(root->right);
        total = 1 + ((left > right) ? left : right);
    }
    return total;
}

// return a pointer to a copy of a tree
tnode * copy(tnode * root)
{
    if (!root)
        return nullptr;

    return new tnode(root->value, copy(root->left), copy(root->right));
}

// delete a subtree
void deleteTree(tnode * root)
{
    if (!root) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// put root of tree to delete the whole tree
void clearTree(tnode * root)
{
    deleteTree(root);
    root = nullptr;
}

int main ()
{
    tnode *root = nullptr;
    root = insert(root, 5);
    insert(root, 9);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 10);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);

    // print all traversal of the BST
    preorder(root);
    std::cout << "\n\n";
    inorder(root);
    std::cout << "\n\n";
    postorder(root);
    std::cout << "\n\n";
    levelorder(root);
    std::cout << "\n\n";

    std::cout << "leaf nodes: " << countleaf(root) << "\n";
    std::cout << "depth: " << depth(root) << "\n";

    tnode *newroot = nullptr;
    std::cout << "copying.\n";
    newroot = copy(root);

    preorder(root);
    std::cout << "\n\n";
    inorder(root);
    std::cout << "\n\n";
    postorder(root);
    std::cout << "\n\n";
    levelorder(root);
    std::cout << "\n\n";

    std::cout << "nodes: " << countleaf(root) << "\n";
    std::cout << "depth: " << depth(root) << "\n";

    std::cout << "deleting trees.\n";
    clearTree(root);
    clearTree(newroot);

    return 0;
}
