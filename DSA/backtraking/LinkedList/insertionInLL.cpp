#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* insertAtEnd(Node* head, int x) {
        Node* newNode = new Node(x);

        if (head == nullptr) {
            return newNode;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;

        return head;
    }

    void printLL(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList list;
    Node* head = nullptr;

    head = list.insertAtEnd(head, 1);
    head = list.insertAtEnd(head, 2);
    head = list.insertAtEnd(head, 3);
    head = list.insertAtEnd(head, 4);

    list.printLL(head);

    return 0;
}
