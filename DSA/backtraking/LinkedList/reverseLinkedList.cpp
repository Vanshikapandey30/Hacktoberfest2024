#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {} // Constructor to initialize the node
};

// Brute-force solution to reverse the linked list using a stack
ListNode* reverseListBruteForce(ListNode* head) {
    ListNode* temp = head;
    stack<int> st;

    // Push all node values onto the stack
    while (temp != NULL) {
        st.push(temp->val);
        temp = temp->next;
    }

    // Pop values from the stack to reverse the linked list
    ListNode* reversedLL = head;
    while (reversedLL != NULL) {
        reversedLL->val = st.top();
        st.pop();
        reversedLL = reversedLL->next;
    }

    return head;
}

// Optimal solution to reverse the linked list in place
ListNode* reverseListOptimal(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // Store the next node
        curr->next = prev;   // Reverse the pointer
        prev = curr;         // Move prev to current node
        curr = next;         // Move to the next node
    }

    return prev; // New head of the reversed linked list
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function to test both reverseList functions
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List: ";
    printList(head);

    // Reversing the linked list using the brute-force approach
    ListNode* bruteReversedHead = reverseListBruteForce(head);
    cout << "Reversed Linked List (Brute-force): ";
    printList(bruteReversedHead);

    // Recreating the linked list for the optimal approach demonstration
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Reversing the linked list using the optimal approach
    ListNode* optimalReversedHead = reverseListOptimal(head);
    cout << "Reversed Linked List (Optimal): ";
    printList(optimalReversedHead);

    return 0;
}
