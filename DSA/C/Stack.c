#include<stdio.h>
int size, top=-1;
int arr[10];

void push(int arr[size],int*top,int size)
{ int element;
    if(*top==size-1)
    {
        printf("Push not a valid expression. Overflow error.\n");
    }
    else
    {
        *top=*top+1;
        printf("Enter the element to be pushed: ");
        scanf("%d", &element);
        arr[*top]=element;
        printf("The element %d has been pushed successfully. \n",element);
    }
}
void pop(int arr[size],int*top,int size)
{ int rem;
    if(*top==-1)
    {
        printf("Pop is not a valid expression. Underflow error.\n");
    }
    else
    {
        rem=arr[*top];
        *top=*top-1;
        printf("The element %d has been popped sucessfully.\n",rem);
    }
}
void display(int arr[size],int*top,int size)
{
    int i;
   

    if(*top==-1)
    {
        printf("The stack is empty. \n");
    }
    else
    {
        printf("The stack is currently: \n");
        for(i=0;i<=*top;i++)
        {
            printf("%d ",arr[i]);
        }
    }
    printf("\n");

}
int main()
{   int size,op,end=0;
    printf("Enter the size of the array:\n");
    scanf("%d",&size);
    while(end!=2)
    {
    printf("Enter the operation to be performed:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
    scanf("%d",&op);

    switch (op)
    {
    case 1:
        push(arr,&top,size);
        break;

    case 2:
        pop(arr,&top,size);
        break;

    case 3:
        display(arr,&top,size);
        break;

    default:
        printf("Invalid Operation.\n");
        end=2;
        break;
    }
    }
}





