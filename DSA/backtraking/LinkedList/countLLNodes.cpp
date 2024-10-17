#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    // Function to count nodes of a linked list.
    int getCount(Node* head) {
        int cnt = 0;
        Node* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
};

int main() {
    // Creating a simple linked list for demonstration: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    Solution sol;
    int count = sol.getCount(head);
    cout << "Number of nodes in the linked list: " << count << endl;

    // Clean up the allocated memory
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
