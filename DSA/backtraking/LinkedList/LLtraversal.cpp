#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct Node
{
    int  data;
    Node* next;
};

void traverseLL(Node* head) 
{
    Node* current = head;
    while(current != nullptr)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<< endl;
}

int main() {

    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};

    cout<<"Linked List Elements : ";
    traverseLL(head);

    return 0;
}
