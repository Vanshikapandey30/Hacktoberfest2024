// Problem statement
// You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.
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

Node* removeDuplicates(Node* head) {
    if (head == nullptr) {
        return head;
    }
    Node* pt1 = head;
    Node* pt2 = head->next;

    while (pt2 != nullptr) {
        if (pt1->data != pt2->data) {
            pt1 = pt1->next;
            pt2 = pt2->next;
        } else {
            Node* temp = pt2;
            pt2 = pt2->next;
            pt1->next = pt2;
            delete temp;
        }
    }
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
    int arr[] = {1, 1, 2, 3, 3, 4, 4, 4, 5};
    Node* head = createList(arr, 9);

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
