#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function for BFS traversal
void bfsTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        // Print the current node's value
        cout << current->val << " ";

        // Add left child to queue if it exists
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // Add right child to queue if it exists
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "BFS Traversal: ";
    bfsTraversal(root);

    return 0;
}
