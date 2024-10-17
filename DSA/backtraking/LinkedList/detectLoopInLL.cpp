#include <bits/stdc++.h>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(NULL) {}
    Node(int data) : data(data), next(NULL) {}
    Node(int data, Node* next) : data(data), next(next) {}
};

// Optimal Solution: Floyd's Cycle Detection Algorithm
bool detectCycleOptimal(Node* head) {
    Node* slow = head; 
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          
        fast = fast->next->next;   

        if (slow == fast) return true; // Cycle detected
    }
    return false; // No cycle found
}

// Brute-force Solution: Using a hash set
bool detectCycleBruteForce(Node* head) {
    unordered_set<Node*> visited;
    Node* current = head;

    while (current != NULL) {
        if (visited.find(current) != visited.end()) return true; // Cycle detected
        visited.insert(current); 
        current = current->next;  
    }
    return false; // No cycle found
}

// Main function to test the algorithms
int main() {
    // Creating a linked list with a cycle
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next; // Creating a cycle (5 -> 3)

    // Test Optimal Solution
    cout << (detectCycleOptimal(head) ? "Cycle detected using optimal method." : "No cycle found using optimal method.") << endl;

    // Resetting the cycle for brute force test
    head->next->next->next->next->next = NULL;

    // Creating a linked list without a cycle
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Test Brute-force Solution
    cout << (detectCycleBruteForce(head) ? "Cycle detected using brute-force method." : "No cycle found using brute-force method.") << endl;

    // Free memory
    delete head->next->next->next->next; // Delete 5
    delete head->next->next->next;        // Delete 4
    delete head->next->next;              // Delete 3
    delete head->next;                    // Delete 2
    delete head;                          // Delete 1

    return 0;
}
