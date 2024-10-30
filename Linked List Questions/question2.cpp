// Problem statement
// You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.

// Hint:
// Identify how many pointers you require and try traversing them to right places and connect nodes accordingly also don't forget to disconnect what's required else it could create cycles.

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

Node* appendLastNToFirst(Node* head, int n) {
    if (head == nullptr) {
        return head;
    }
    int count = 0;
    Node* p1 = head;
    Node* p2 = head;

    while (p1->next != nullptr) {
        count++;
        p1 = p1->next;
    }
    p1->next = head;

    for (int i = 0; i < count - n; i++) {
        p2 = p2->next;
    }

    head = p2->next;
    p2->next = nullptr;
    return head;
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
    head = appendLastNToFirst(head, n);

    cout << "List after appending last " << n << " nodes to the front: ";
    printList(head);

    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
