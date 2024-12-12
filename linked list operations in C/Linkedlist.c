#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    struct Node* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    int key = 20;
    if (search(head, key)) {
        printf("Key %d found in the list.\n", key);
    } else {
        printf("Key %d not found in the list.\n", key);
    }

    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    
    return 0;
}
