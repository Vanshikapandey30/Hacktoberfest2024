#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 10

int a[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value);
int dequeue();
void display();

int main() {
    int choice, value;
    while (true) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    a[rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = a[front];
    front++;
    if (front > rear) {
        front = rear = -1;
    }
    return value;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
