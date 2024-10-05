#include<stdio.h>
#include<iostream>
using namespace std;
struct node
{
    node *next;
    int item;
};
class CLL
{
   private :
          node *last;

    public :
          CLL();
          void insertfirst(int);
          void insertafternode(node *,int);
          void insertlast(int);
          node* search(int);
          void deletefirst();
          void deleteafternode(node*);
          void deletelast();
          void display();
          ~CLL();
};
CLL::CLL()
{
    last = NULL;
}
void CLL::insertfirst(int data)
{
    node *n;
    n = new node;
    n->item = data;
    if (last==NULL)
     {
        n->next = last;
        last = n;
     }
    else 
     {
        n->next = last->next;
        last->next = n;
     }
}
void CLL::insertlast(int data)
{
    if (last==NULL)
      insertfirst(data);
    else 
    {
        node *n = new node;
        n->next = last->next;
        last = n;
    }
}
void CLL::deletefirst()
{
    if (last==NULL)
      cout<<"List is empty";
    else if (last==last->next)
    {
        node *r;
        r = last->next;
        last->next = r->next;
        delete r;
        last = NULL;
    }
    else 
    {
        node *r;
        r = last->next;
        last->next = r->next;
        delete r;
    }
}
void CLL::deletelast()
{
    if (last==NULL)
     cout<<"List is empty";
    else if (last==last->next)
      deletefirst();
    else 
    {
        node *t;
        t=last->next;
        while(t->next!=last)
          t=t->next;
        t->next=last->next;
        last = t;
    }
}
node* CLL::search(int data)
{
     node *t;
     t=last->next;
     while(t!=last)
      {
        if (t->item == data)
          return t;
         else 
          t=t->next;
      }
      return NULL;
}
void CLL::insertafternode(node *t,int data)
{
    node *n = new node;
    n->item=data;
    if (t==last)
     insertlast(data);
    else 
    {
        n->next = t->next;
        t->next = n; 
    }
}
void CLL::deleteafternode(node*t)
{
    node *r;
    if(t!=NULL)
     {
        if(t==last)
         deletelast();
         else if(t=last->next)
          deletefirst();
          else{
            r=last->next;
            while(r->next!=t)
             r=r->next;
             r->next = t->next;
             delete t;
          }
     }
}
void CLL:: display()
          {
             node *t;
             t=last->next;
             cout<<t->item<<" ";
             while(t!=last)
             {
               cout<<t->item<<" ";
               t=t->next;
             }
          }
CLL::~CLL()
{
    while(last)
     deletefirst();
}
int main()
{
 CLL a;
    int choice;
 while(1)
  {
    cout<<"----*MENU*---\n";
    cout<<"1.Insert at first \n";
    cout<<"2.Search\n";
    cout<<"3.Insert at last \n";
    cout<<"4.Insert node \n";
    cout<<"5.Delete first node\n";
    cout<<"6.Delete node \n";
    cout<<"7.Delete last node\n";
    cout<<"8. Display \n";
    cout<<"9.EXIT\n";
    cout<<"ENTER A CHOICE : \t";
    cin>>choice;
    switch(choice)
    {
        case 1 :
              int data;
              cout<<"Enter data : \t";
              cin>>data;
              a.insertfirst(data);
              break;
        case 2 :
              cout<<"Enter data";
             cin>>data;
             node *save;
             save = a.search(data);
             (save==0)?cout<<"NOT FOUND":cout<<"FOUND";
             break;
        case 3 :
             cout<<"Enter data";
             cin>>data;
             a.insertlast(data);
             break;
        case 4 :
              cout<<"Enter data : \t";
              cin>>data;
              a.insertafternode(save,data);
              break;
        case 5 :
             a.deletefirst();
             break;
        case 6 :
              a.deleteafternode(save);
              break;
        case 7 :
              a.deletelast();
              break;
        case 8 :
              a.display();
              break;
        case 9 :
              exit(0);
        default :
              cout<<"Wrong choice";
    }
  }
}
