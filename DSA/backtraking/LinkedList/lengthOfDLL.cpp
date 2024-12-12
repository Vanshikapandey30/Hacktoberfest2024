#include <iostream>

using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node * prev;
    Node * next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

// Function to find the length of a doubly 
//linked list
int findLength(Node * head) {
    int count = 0;
    for (Node * cur = head; cur != nullptr; cur = cur -> next)
        count++;
    return count;
}

int main() {

    // Create a DLL with 3 nodes
    Node * head = new Node(1);
    Node * second = new Node(2);
    Node * third = new Node(3);
    head -> next = second;
    second -> prev = head;
    second -> next = third;
    third -> prev = second;

    cout << "Length of the doubly linked list: " <<
        findLength(head) << endl;

    return 0;
}