#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Function to delete a node in the linked list.
    void deleteNode(ListNode* faiz) {
        if (faiz == nullptr || faiz->next == nullptr) {
            return; // Cannot delete if the node is null or the last node.
        }
        faiz->val = faiz->next->val;    // Copy the value from the next node
        ListNode* temp = faiz->next;    // Temporarily hold the next node
        faiz->next = faiz->next->next;   // Bypass the next node
        delete temp;                    // Free the memory of the deleted node
    }
};

int main() {
    // Creating a simple linked list for demonstration: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Demonstrating deleteNode by deleting the second node (value 2)
    Solution sol;
    sol.deleteNode(head->next); // This will delete the node with value 2

    // Print the updated linked list
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up the allocated memory
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
