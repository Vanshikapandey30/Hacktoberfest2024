#include <stdio.h>
#include <stdlib.h>

struct Node{
    int a;
    struct Node* next;
    struct Node* prev;
};

struct Stack {
    struct Node* top;
};

void push(int data, struct Stack* stack){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->a = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (stack->top == NULL){  // Stack is empty
        stack->top = newNode;
    } 
    else {
        newNode->next = stack->top;
        stack->top->prev = newNode;
        stack->top = newNode;  // Update top to the new node
    }
}

int pop(struct Stack* stack){
    if (stack->top == NULL){  // Stack is empty
        printf("Stack is empty\n");
        return -1;
    }

    struct Node* temp = stack->top;
    int data = temp->a;

    stack->top = stack->top->next;

    if (stack->top != NULL) {
        stack->top->prev = NULL;  // Update top's prev to NULL
    }

    free(temp);
    return data;
}

void printStack(struct Stack* stack){
    struct Node* temp = stack->top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    while (temp != NULL){
        printf("%d ", temp->a);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Stack stack;
    stack.top = NULL;

    int n;
    printf("Haan bhai kitne number daalega??:");
    scanf("%d", &n);
    printf("Daal fir (Push):\n");

    for (int i = 0; i < n; i++){
        int z;
        scanf("%d", &z);
        push(z, &stack);
    }

    printf("Stack after push operations: ");
    printStack(&stack);

    printf("Popping elements:\n");
    for (int i = 0; i < n; i++){
        int popped = pop(&stack);
        if (popped != -1)
            printf("Popped: %d\n", popped);
    }

    printf("Stack after pop operations: ");
    printStack(&stack);

    return 0;
}
