#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

// Brute Force Approach
ListNode* middleNodeBruteForce(ListNode* head) {
    int numOfNodes = 0;
    ListNode* tempLL = head;

    while (tempLL) {
        numOfNodes++;
        tempLL = tempLL->next;
    }

    int middleNodeIndex = numOfNodes / 2;
    ListNode* curr = head;

    while (middleNodeIndex--) {
        curr = curr->next;
    }
    return curr;
}

// Optimal Approach
ListNode* middleNodeOptimal(ListNode* head) {
    ListNode* middle = head;
    ListNode* end = head;

    while (end != NULL && end->next != NULL) {
        middle = middle->next;
        end = end->next->next;
    }
    return middle;
}

void printFromMiddle(ListNode* head) {
    while (head) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* middleBruteForce = middleNodeBruteForce(head);
    cout << "Brute Force - Elements from the middle to the end: ";
    printFromMiddle(middleBruteForce);

    ListNode* middleOptimal = middleNodeOptimal(head);
    cout << "Optimal - Elements from the middle to the end: ";
    printFromMiddle(middleOptimal);

    return 0;
}
