#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    node *next;
    int item;
};
class SLL
{
    private :
        node *start;

    public :
          SLL()
          {
            start = NULL;
          }
          void insertatstart(int data)
          {
            if (start==NULL)
              {
                node *ptr = new node; 
                ptr->item = data;
                ptr->next = NULL;
                start = ptr;
              }
             else 
             {
              cout<<"Wrong choice";
             }
          }
          void insertafternode(node *t,int data)
          {
            node *n;
            if(t)
            {
              n=new node;
              n->item = data;
              n->next = t->next;
              t->next = n;
            }
          }
          void insertatlast(int data)
          {
             node *temp;
             temp = start;
             while(temp->next)
             {
                  temp = temp->next;
             }
             node *ptr = new node;
             ptr->item = data;
             ptr->next = NULL;
             temp->next = ptr;
             temp = ptr;
          }
          void deletefirst()
          {
            if (start == NULL)
            {
                cout<<"List Empty \n";
            }
            else 
            {
                node*r;
                r = start;
                start =r->next;
                delete r;
            }
          }
          void deletenode(node *t)
          {
             if (start == NULL)
               cout<<"Empty list";
             if(start == t)
               deletefirst();
              else
             {
              node *r;
              r=start;
              while(r->next!=t)
                r=r->next;
              r->next=t->next;
              delete t;
             }
          }
          void deletelast()
          {
             node *temp;
            if(start == NULL)
             cout<<"List is Empty";
            else if (start->next == NULL)
            { 
                delete start;
                start = NULL;
            }
            else
            {
             temp = start;
             while(temp->next!=NULL)
             {
                 temp = temp->next;
             }
             delete temp->next;
             temp->next = NULL;
            }
          }
          node* search(int data)
          {
            node *t;
            t=start;
            while (t)
            {
              if (t->item==data)
               return t;
              else 
               t= t->next;
            }
            return NULL;
          }
          void display()
          {
             node *t;
             t=start;
             while(t)
             {
               cout<<t->item<<" ";
               t=t->next;
             }
          }
          ~SLL()
          {
            while(start)
              deletefirst();
          }
};
int main()
{
 SLL a;
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
              a.insertatstart(data);
              break;
        case 2 :
              cout<<"Enter data";
             cin>>data;
             node *save;
             save = a.search(data);
             break;
        case 3 :
             cout<<"Enter data";
             cin>>data;
             a.insertatlast(data);
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
