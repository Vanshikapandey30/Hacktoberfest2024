#include<bits/stdc++.h>
using namespace std;

using namespace std;

struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
    DLLNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

DLLNode* reverseDLL(DLLNode* head) {
    stack<int> st;
    DLLNode* temp = head;

    while (temp != nullptr) {
        st.push(temp->data);
        temp = temp->next;
    }

    DLLNode* current = head;
    while (current != nullptr) {
        current->data = st.top();
        st.pop();
        current = current->next;
    }
    return head;
}

void printDLL(DLLNode* head) {
    DLLNode* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    DLLNode* head = new DLLNode(1);
    head->next = new DLLNode(2);
    head->next->prev = head;
    head->next->next = new DLLNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = new DLLNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new DLLNode(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original Doubly Linked List: ";
    printDLL(head);

    head = reverseDLL(head);
    
    cout << "Reversed Doubly Linked List: ";
    printDLL(head);

    return 0;
}
