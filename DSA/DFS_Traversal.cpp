#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function for DFS traversal (Pre-order)
void dfsTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Print the current node's value (Pre-order traversal)
    cout << root->val << " ";

    // Recursively traverse the left subtree
    dfsTraversal(root->left);

    // Recursively traverse the right subtree
    dfsTraversal(root->right);
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "DFS Traversal (Pre-order): ";
    dfsTraversal(root);

    return 0;
}
