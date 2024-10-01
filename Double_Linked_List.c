#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int a;
    struct Node* next;
    struct Node* prev;
};

int insert(int data, struct Node** head){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->a = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL){
        *head = newNode;
    }
    else{
        struct Node* temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp; 
    }
}

int print(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL){
        printf("%d ", temp->a);
        temp = temp->next;
    }
}

int printReverse(struct Node* head){
    struct Node* temp = head;
    
    
    while (temp->next != NULL){
        temp = temp->next;
    }

    while (temp != NULL){
        printf("%d ", temp->a);
        temp = temp->prev;
    }
}

int main(){
    struct Node* head = NULL;
    int n;
    printf("Haan bhai kitne number daalega??:");
    scanf("%d", &n);
    printf("Daal fir:");

    for (int i = 0; i < n; i++){
        int z;
        scanf("%d", &z);
        insert(z, &head);
    }

    printf("Linked List in forward order: ");
    print(head);
    printf("\nLinked List in reverse order: ");
    printReverse(head);

    return 0;
}
