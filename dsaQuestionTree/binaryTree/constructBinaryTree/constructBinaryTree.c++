#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node *right, *left;

    Node(int v) {
        val = v;
        right = left = NULL;
    }
};

// Helper function to build the tree
Node* buildTreeHelper(vector<int> &preorder, int preStart, int preEnd,
                      vector<int> &inorder, int inStart, int inEnd,
                      unordered_map<int, int> &mp) {
    // Base case: if no elements to construct the tree
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }

    // Create root node with the first value in preorder traversal
    Node* root = new Node(preorder[preStart]);

    // Get the index of the root in the inorder traversal
    int rootInorderIndex = mp[root->val];

    // Calculate the size of the left subtree
    int leftSubtreeSize = rootInorderIndex - inStart;

    // Recursively build the left and right subtrees
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize,
                                 inorder, inStart, rootInorderIndex - 1, mp);
    root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd,
                                  inorder, rootInorderIndex + 1, inEnd, mp);
    
    return root;
}

// Helper function to print the tree in inorder (for debugging purposes)
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Inorder and preorder traversal vectors
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    // Map to store the index of each element in inorder traversal for quick lookup
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
    }

    // Build the tree using the helper function
    Node* root = buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);

    // Print the inorder traversal of the constructed tree
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);  // This will help you verify if the tree was built correctly
    
    return 0;
}
