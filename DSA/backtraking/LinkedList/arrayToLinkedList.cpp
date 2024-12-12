#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* constructLL(vector<int>& arr) {
        if (arr.empty()) return nullptr;
        
        Node *newHead = new Node(arr[0]);
        Node *temp = newHead;
        
        for (int i = 1; i < arr.size(); i++) {
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
        return newHead;
    }
};

void printLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    
    Solution solution;
    Node* head = solution.constructLL(arr);
    
    printLL(head);

    return 0;
}
