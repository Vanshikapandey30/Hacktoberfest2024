#include <iostream>
#include <queue> // Include queue for level order traversal
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function for level order traversal
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q; // Create a queue to hold nodes at each level
    q.push(root); // Start with the root node

    while (!q.empty()) {
        TreeNode* current = q.front(); // Get the front node
        q.pop(); // Remove it from the queue

        // Visit the current node
        cout << current->val << " ";

        // Add the left child to the queue if it exists
        if (current->left) {
            q.push(current->left);
        }
        // Add the right child to the queue if it exists
        if (current->right) {
            q.push(current->right);
        }
    }
}

int main() {
    // Creating a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Level order traversal of the binary tree is: ";
    levelOrderTraversal(root);
    cout << endl;

    // Clean up memory (delete nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
