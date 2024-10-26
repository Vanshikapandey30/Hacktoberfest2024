#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    void insert(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        insert(root, value);
    }

    void inOrderTraversal() {
        inOrder(root);
    }
};

int main() {
    BST tree;

    int n, value;
    std::cout << "Enter the number of elements you want to insert: ";
    std::cin >> n;

    std::cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        tree.insert(value);
    }

    std::cout << "Sorted values (in-order traversal): ";
    tree.inOrderTraversal();
    std::cout << std::endl;

    return 0;
}
