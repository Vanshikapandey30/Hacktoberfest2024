#include <iostream>
using namespace std;

// Structure of a Node
struct Node {
    int data;
    Node* next;
};

// Function to search for a key in the linked list
bool searchKey(Node* head, int key) {
    while (head != nullptr) {
        if (head->data == key) {
            return true;
        }
        head = head->next;
    }
    return false;
}

// Example usage
int main() {
    // Creating a simple linked list
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};

    // Searching for keys
    cout << (searchKey(head, 20) ? "Found" : "Not Found") << endl; // Output: Found
    cout << (searchKey(head, 40) ? "Found" : "Not Found") << endl; // Output: Not Found

    return 0;
}
