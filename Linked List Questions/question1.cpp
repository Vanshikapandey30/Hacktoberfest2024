#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int findNode(Node* head, int n) {
    Node* temp = head;
    for (int i = 0; temp != nullptr; i++) {
        if (n == temp->data) {
            return i;
        }
        temp = temp->next;
    }
    return -1;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

Node* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = createList(arr, 5);

    cout << "Original List: ";
    printList(head);

    int n = 3;
    int index = findNode(head, n);
    if (index != -1) {
        cout << "Element " << n << " found at index: " << index << endl;
    } else {
        cout << "Element " << n << " not found in the list." << endl;
    }

    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
