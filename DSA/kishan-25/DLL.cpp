#include<stdio.h>
#include<iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class DLL
{
    private :
          node *start;

    public :
          DLL();
          void insertfirst(int);
          void insertnode(node *,int);
          void insertlast(int);
          node* search(int);
          void deletefirst();
          void deletenode(node*);
          void deletelast();
          void display();
          ~DLL();
};
DLL::DLL()
{
   start=NULL;
}  
void DLL::insertfirst(int data)
{
  if(start==NULL)
   {
    node *n;
    n = new node;
    n->item = data;
    n->prev = start;
    n->next = NULL;
    start = n;
   }
   else 
   {
     node *n;
     n=new node;
     n->item = data;
     n->prev = start;
     n->next = start->next;
     start = n; 
   }
}
void DLL::insertnode (node *t,int data)
{
    node *n;
    if (t->next==NULL)
    {
      insertlast(data);
    }
    else 
    {
        n = new node;
        n->item = data;
        n->prev = t->next;
        n->next = t->next;
        t->next = n;
    }
}
void DLL:: insertlast(int data)
{
    node *t;
    node *n;
    n=new node ;
    n->item = data;
    n->next = NULL;
    if(start==NULL)
      n->prev=NULL;
    else
    {
    t = start;
    while (t->next!=NULL)
    {
       t=t->next;
    }
    n->prev = t;
    t->next = n;
    }
}
node* DLL :: search(int data)
{
    node *t;
    t = start;
    while(t)
    {
        if(t->item==data)
         return t;
        else 
          t=t->next;
    }
    return NULL;
}
void DLL::deletefirst()
{
    if (start==NULL)
      cout<<"List is empty";
    else 
      {
        node *r ;
        r = start;
        start = r->next;
        start->prev = NULL;
        delete r;
      }
}
void DLL::deletenode(node *t)
{
    if(start==NULL)
    cout<<"List is empty";
    else if (start==t)
     deletefirst();
    else if(t->next==NULL)
     deletelast();
    else
    {
    t->prev->next = t->next;
    t->next->prev = t->prev;
    delete t;
    }
}
void DLL::deletelast()
{
    if(start->next==NULL)
     deletefirst();
    else if (start==NULL)
      cout<<"List is empty";
    else 
    {
      node *t;
      t = start;
      while(t)
        t=t->next;
      t->prev->next = NULL;
      delete t;
    } 
}
DLL::~DLL()
{
    while(start)
     deletefirst();
}
 void DLL:: display()
          {
             node *t;
             t=start;
             while(t)
             {
               cout<<t->item<<" ";
               t=t->next;
             }
          }
int main()
{
 DLL a;
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
              a.insertnode(save,data);
              break;
        case 5 :
             a.deletefirst();
             break;
        case 6 :
              a.deletenode(save);
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
