#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
  int coeff,pow;
  struct node *next;
}*start1=NULL,*start2=NULL,*start=NULL,*start3=NULL,*p,*p1,*p2,*temp,*a=NULL;

void create(struct node *);
void display(struct node *);
void add(struct node *,struct node *,struct node *);
void sub(struct node *,struct node *,struct node *);

void main()
{
 start1=(struct node *)malloc(sizeof(struct node));
 start2=(struct node *)malloc(sizeof(struct node));
 start3=(struct node *)malloc(sizeof(struct node));
 printf("\nEnter 1st Polynomial\n");
 create(start1);
 printf("\nEnter 2nd Polynomial\n");
 create(start2);
 printf("\n1st Polynomial\n");
 display(start1);
 printf("\n2nd Polynomial\n");
 display(start2);
 add(start1,start2,start3);
 printf("\nAdded Polynomial: \n");
 display(start3);
 start3=NULL;
 sub(start1,start2,start3);
 printf("\nSubtracted Polynomial: \n");
 display(start3);
 getch();
}


void create(struct node *temp)
{
 char ch;
 do
 {
  printf("Enter coefficient and power\n ");
  scanf("%d%d",&temp->coeff,&temp->pow);
  temp->next=(struct node *)malloc(sizeof(struct node));
  temp=temp->next;
  temp->next=NULL;
  printf("Press y to continue\n");
  ch=getch();             
 }while(ch=='y'|| ch=='Y');
}


void display(struct node *start)
{
 p=start;
 while(p->next!=NULL)
 {
  printf("%dx^%d",p->coeff,p->pow);
  p=p->next;
  if(p->next!=NULL)
   printf(" + ");
 }
printf("\n");
}

//-------ADDITION-------
void add(struct node *start1,struct node *start2,struct node *start3)
{
 while(start1->next && start2->next)
 {
  if(start1->pow==start2->pow)
  {
   start3->coeff=start1->coeff+start2->coeff;
   start3->pow=start1->pow;
   start1=start1->next;
   start2=start2->next;
  }
  else if(start1->pow > start2->pow)
  {
   start3->coeff=start1->coeff;
   start3->pow=start1->pow;
   start1=start1->next;
  }
  else
  {
   start3->coeff=start2->coeff;
   start3->pow=start2->pow;
   start2=start2->next;
  }
  start3->next=(struct node *)malloc(sizeof (struct node));
  start3=start3->next;
  start3->next=NULL;
 }
 while(start1->next || start2->next)
 {
  if(start1->next)
  {
   start3->pow=start1->pow;
   start3->coeff=start1->coeff;
   start1=start1->next;
  }
  if(start2->next)
  {
   start3->coeff=start2->coeff;
   start3->pow=start2->pow;
   start2=start2->next;
  }
  start3->next=(struct node *)malloc(sizeof(struct node));
  start3=start3->next;
  start3->next=NULL;
 }
}

//-------SUBTRACTION-------
void sub(struct node *start1,struct node *start2,struct node *start3)
{
 while(start1->next && start2->next)
 {
  if(start1->pow==start2->pow)
  {
   start3->coeff=start1->coeff-start2->coeff;
   start3->pow=start1->pow;
   start1=start1->next;
   start2=start2->next;
  }
  else if(start1->pow > start2->pow)
  {
   start3->coeff=start1->coeff;
   start3->pow=start1->pow;
   start1=start1->next;
  }
  else
  {
   start3->coeff=-start2->coeff;
   start3->pow=start2->pow;
   start2=start2->next;
  }
  start3->next=(struct node *)malloc(sizeof (struct node));
  start3=start3->next;
  start3->next=NULL;
  }
  while(start1->next || start2->next)
  {
   if(start1->next)
   {
    start3->pow=start1->pow;
    start3->coeff=start1->coeff;
    start1=start1->next;
   }
  if(start2->next)
  {
   start3->coeff=start2->coeff;
   start3->pow=start2->pow;
   start2=start2->next;
  }
  start3->next=(struct node *)malloc(sizeof(struct node));
  start3=start3->next;
  start3->next=NULL;
 }
}