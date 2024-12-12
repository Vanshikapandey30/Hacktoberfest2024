#include <stdio.h>
#include <stdlib.h>
struct node
{
    char stu_name[100];
    int stu_id;
    int stu_rollno;
    int stu_batch;
    struct node *next;
} *head, *temp;

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    create(n);
    delete_record();
    printlist();
    return 0;
}

void create(int n)
{
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("No memmory allocated");
    }
    else
    {
        printf("Enter the record of student 1:\n");
        printf("Enter name: ");
        scanf("%s",head->stu_name);
        getchar();
        printf("Enter id: ");
        scanf("%d", &head->stu_id);
        printf("Enter roll no: ");
        scanf("%d", &head->stu_rollno);
        printf("Enter batch: ");
        scanf("%d", &head->stu_batch);
        temp = head;
        for (int i = 2; i < n; i++)
        {
            struct node *newnode;
            newnode = (struct node *)malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("NO memory allocated");
            }
            printf("Enter the record of student %d\n", i);
            printf("Enter name: ");
            scanf("%s", newnode->stu_name);
            getchar();
            printf("Enter id: ");
            scanf("%d", &newnode->stu_id);
            printf("Enter roll no: ");
            scanf("%d", &newnode->stu_rollno);
            printf("Enter batch: ");
            scanf("%d", &newnode->stu_batch);
            newnode->next=NULL;
            temp->next=newnode;
            temp=temp->next;
        }
    }
}
