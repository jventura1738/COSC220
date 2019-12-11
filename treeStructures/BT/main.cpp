#include <iostream>
#include "tnode.h"
#include <queue>

// do inorder traversal of BT.
void inorder(tnode *root)
{
    if (!root) return;

    if (root->left)
        inorder(root->left);

    std::cout << root->value << "\n";

    if (root->right)
        inorder(root->right);
}

// do preorder traversal of BT.
void preorder(tnode *root)
{
    if (!root) return;

    std::cout << root->value << "\n";

    if (root->left)
        preorder(root->left);

    if (root->right)
        preorder(root->right);
}

// do postorder traversal of BT.
void postorder(tnode* root)
{
    if (!root) return;

    if (root->left)
        postorder(root->left);

    if (root->right)
        postorder(root->right);

    std::cout << root->value << "\n";
}

// print BT in level order.
void levelorder(tnode* root)
{
    // if root pointer points to nothing.
    if (!root)
    {
        std::cout << "Tree does not exist.\n";
        return;
    }

    // queue to keep track of nodes on a level. will use
    // nullptr to mark a new level. as the queue pops, 
    // curr will temporarily hold the value to be printed. 
    std::queue <tnode*> q;
    tnode *curr;

    // marks new level since root level (0) only has node.
    q.push(root);
    q.push(nullptr); // new level mark.

    // loop over the tree.  use a queue to keep track
    // of tree level node values.
    while (q.size() > 1)
    {
        // use curr to take this node into account.
        // pop the node since it is accounted for now.
        curr = q.front();
        q.pop();

        // if curr held nullptr, then we mark a new level.
        // if that was the last level, while will end.
        if (!curr)
        {
            q.push(nullptr);
            std::cout << "\n";
        }

        // push curr's left & right children, if any.
        else
        {
            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);

            std::cout << curr << " ";
        }
    }
    std::cout << "\n";
}

// insert a new node with given key in BT.
tnode* insert(tnode* root, int key)
{
    // if the tree is empty, make a new root.
    if (!root)
        return root = new tnode(key);

    // else, recur down the tree.
    if (key < root->value)
        root->left = insert(root->left, key);

    else if (key > root->value)
        root->right = insert(root->right, key);

    // return the (unchanged) root pointer.
    return root;
}

// count leaf nodes for BT given root.
// pre-order traversal application.
int countleaf(tnode* root)
{
    // for nullptr root & leaf "children."
    if (!root)
        return 0;

    // if node has no children, it is a leaf.
    if (!root->left && !root->right)
        return 1;

    // else, recur down the tree.
    // return leaves from L&R subtrees.
    else
        return (countleaf(root->left) + countleaf(root->right));
}

// get depth of BT.
// post-order traversal application.
int depth(tnode* root)
{
    // depth of left& right subtrees & total.
    int left, right, total;

    // if no node, then remove extra edge.
    if (!root)
        return -1;

    // get the max of the left & right subtrees.
    else
    {
        // depths of the right & left subtrees.
        left = depth(root->left);
        right = depth(root->right);

        // add one for each recursively counted edge.
        total = 1 + ((left > right) ? left : right);
    }
    return total;
}

// return a pointer to a copy of a tree.
// post-order traversal application.
tnode * copy(tnode * root)
{
    if (!root)
        return nullptr;

    return new tnode(root->value, copy(root->left), copy(root->right));
}

// delete a subtree.
// post-order traversal application.
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
