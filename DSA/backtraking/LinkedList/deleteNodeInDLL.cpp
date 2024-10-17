#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};

// Function to create a linked list from a vector of integers
Node* createLinkedList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (size_t i = 1; i < arr.size(); ++i) {
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->back = current;
        current = newNode;
    }
    return head;
}

Node* deleteHead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    delete prev;
    return head;
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = createLinkedList(arr);

    head = deleteHead(head);
    print(head);

    return 0;
}
