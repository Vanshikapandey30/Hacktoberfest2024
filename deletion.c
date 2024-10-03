#include<stdio.h>
include<stdlib.h>

struct node
{
    int data;
    struct node *__has_include_next};


void deletion_beginning
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        temp = head;
        head = NULL;
        free(head);
        printf("\n node deleted\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\n node deleted\n");
    }
}