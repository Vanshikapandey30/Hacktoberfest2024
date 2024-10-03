#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Depth First Search (DFS) for traversing the tree : there are three types of DFS
// 1. Preorder : root, left, right
// 2. Inorder : left, root, right
// 3. Postorder : left, right, root
// Preorder, Inorder, Postorder are also called as Tree Traversals
// Time complexity: O(n) where n is the number of nodes in the tree
// Space complexity: O(h) where h is the height of the tree
// In DFS, we need to keep track of visited nodes to avoid revisiting them
// The order of traversal can be controlled by changing the order of the if-else statements in the recursive calls
// In DFS, we can also use a stack to keep track of the nodes to visit
// In DFS, we can also use a recursive function or an iterative function with a stack
// DFS can be implemented using a recursive approach or an iterative approach with a stack

// Recursive preorder traversal (Root -> Left -> Right)
void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Iterative Preorder Traversal using stack (Root -> Left -> Right)
void iterativePreorder(node *root)
{
    if (root == NULL)
        return;

    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {
        root = s.top();
        s.pop();

        cout << root->data << " "; // Process the root

        // Push right and then left child to the stack
        if (root->right)
            s.push(root->right);
        if (root->left)
            s.push(root->left);
    }
    return;
}

// Recursive Inorder traversal (Left -> Root -> Right)
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// Iterative Inorder Traversal using stack (Left -> Root -> Right)
void iterativeInorder(node *root)
{
    stack<node *> s;

    while (root != NULL || !s.empty())
    {
        // Reach the leftmost node
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }

        // Process the node
        root = s.top();
        s.pop();
        cout << root->data << " "; // Process the root

        // Now visit the right subtree
        root = root->right;
    }
}

// Recursive Postorder traversal (Left -> Right -> Root)
void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
// Iterative Postorder Traversal using two stacks (Left -> Right -> Root)
void iterativePostorder(node *root)
{
    if (root == NULL)
        return;

    stack<node *> s1, s2;
    s1.push(root);

    // s1 will be used to collect nodes, s2 will store them in postorder
    while (!s1.empty())
    {
        node *root = s1.top();
        s1.pop();
        s2.push(root);

        // Push left and then right child
        if (root->left)
            s1.push(root->left);
        if (root->right)
            s1.push(root->right);
    }

    // Print nodes from stack s2 (in postorder)
    while (!s2.empty())
    {
        node *root = s2.top();
        s2.pop();
        cout << root->data << " ";
    }
}

// Breadth First search (BFS) for traversing the tree : Level order traversal
// Start from the root node and visit all the nodes at the rootent level before moving to the next level
// Repeat this process until all nodes have been visited
// BFS is particularly useful for finding shortest paths and finding connected components in a graph
// Time complexity: O(n) where n is the number of nodes in the tree
// Space complexity: O(n) where n is the number of nodes in the tree

void levelOrder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // Tree looks like this:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5  6  7

    // Performing preorder, inorder, postorder, and level order traversals

    cout << "Preorder traversal: ";
    iterativePreorder(root);
    cout << "\nInorder traversal: ";
    iterativeInorder(root);
    cout << "\nPostorder traversal: ";
    iterativePostorder(root);
    cout << "\nLevel order traversal: ";
    levelOrder(root);

    return 0;
}