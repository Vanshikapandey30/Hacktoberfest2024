#include <stdio.h>
#include <stdlib.h>

struct Node{
    int a;
    struct Node* next;
    struct Node* prev;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void enqueue(int data, struct Queue* queue){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->a = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (queue->rear == NULL){  // Queue is empty
        queue->front = queue->rear = newNode;
    } 
    else {
        queue->rear->next = newNode;
        newNode->prev = queue->rear;
        queue->rear = newNode; // Update rear to the new node
    }
}

int dequeue(struct Queue* queue){
    if (queue->front == NULL){  // Queue is empty
        printf("Queue is empty\n");
        return -1;
    }

    struct Node* temp = queue->front;
    int data = temp->a;

    queue->front = queue->front->next;

    if (queue->front != NULL) {
        queue->front->prev = NULL; // Update front's prev to NULL
    } else {
        queue->rear = NULL; // If the queue is now empty
    }

    free(temp);
    return data;
}

void printQueue(struct Queue* queue){
    struct Node* temp = queue->front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    while (temp != NULL){
        printf("%d ", temp->a);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Queue queue;
    queue.front = NULL;
    queue.rear = NULL;

    int n;
    printf("Haan bhai kitne number daalega??:");
    scanf("%d", &n);
    printf("Daal fir (Enqueue):\n");

    for (int i = 0; i < n; i++){
        int z;
        scanf("%d", &z);
        enqueue(z, &queue);
    }

    printf("Queue after enqueue operations: ");
    printQueue(&queue);

    printf("Dequeueing elements:\n");
    for (int i = 0; i < n; i++){
        int dequeued = dequeue(&queue);
        if (dequeued != -1)
            printf("Dequeued: %d\n", dequeued);
    }

    printf("Queue after dequeue operations: ");
    printQueue(&queue);

    return 0;
}
