#include <stdio.h>
#include<stdlib.h>

struct node
{
    int coeff,expo;
    struct node * next;
};

struct node * insert(struct node * head,int co ,int ex)
{
    struct node * tmp ,*ptr;
   
    tmp=(struct node *)malloc(sizeof(struct node));
   
    tmp->coeff=co;
    tmp->expo=ex;
    tmp->next=NULL;
   
    if(head==NULL)
    {
        head=tmp;
    }
   
    else
    {
       ptr=head;
       while(ptr->next!=NULL)
       {
           ptr=ptr->next;
       }
       ptr->next=tmp;
    }
    return head;
}

struct node * create(struct node * head)
{
    int n,i,coeff,expo;
    printf("Enter no of terms:\n");
    scanf("%d",&n);
   
    for(i=0;i<n;i++)
    {
        printf("Enter Coefiicient for the term:%d \n",i+1);
        scanf("%d",&coeff);
        printf("Enter Exponential for term:%d \n",i+1);
        scanf("%d",&expo);
       
        head=insert(head, coeff,expo);
    }
    return head;
}

void display(struct node * head)
{
    struct node * ptr;
    ptr=head;
   
    if(head==NULL)
    {
        printf("NO POLYNOMIAL\n");
    }
   
    else
    {
        while(ptr!=NULL)
        {
            printf("%dx^%d",ptr->coeff,ptr->expo);
            ptr=ptr->next;
           
            if(ptr!=NULL)
            {
                printf("+");
            }
            else
            {
                return;
            }
        }
    }
}



int main()
{
    struct node * head=NULL;
    printf("Enter Polynomial:\n");
    head=create(head);
    display(head);
 
    return 0;
}
