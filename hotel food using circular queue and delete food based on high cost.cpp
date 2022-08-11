#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
class node
{
 public:
    string dname;
    int price;
    node*next;
    node*prev;

    node* getdata(node*h)
    {
        node*t=h;
        cout<<"Enter the dish name:";
        cin>>dname;
        cout<<"Enter the price:";
        cin>>price;
        node*nn=new node();
        nn->dname=dname;
        nn->price=price;
        nn->next=NULL;
        nn->prev=NULL;
        if(h==NULL)
        {
           nn->prev=nn;
           nn->next=nn;
           h=nn;
           return h;
        }
       while(t->next!=h)
        {
         t=t->next;
        }
        nn->prev=t;
        t->next=nn;
        nn->next=t;
        t->prev=nn;
        return t;
    }

    node* deletee(node*h)
    {
     if(h==NULL)
     {
      cout<<"No items to delete\n";
      return h;
     }


     node* maxx=h;
     node*t=h->next;


     while(t!=h)
     {
      if(maxx->price < t->price)
        maxx=t;
        t=t->next;
     }
     node*y=maxx->prev;
     node*x=maxx->next;
     x->prev=y;
     y->next=x;
     if(maxx==h)
        h=x;
     delete(maxx);
     cout<<"Item deleted\n";
     return h;
    }

    void display(node*h)
    {
        node*t=h;
        if(h==NULL)
        {
            cout<<"List is empty\n";
            return ;
        }
        cout<<"\n---MENU---\n";
        do
        {
            cout<<t->dname<<"\tRs."<<t->price<<endl;
            t=t->next;
        }while(t!=h);
    }
};
int main()
{
    node m;
    int ch;
    node*head=NULL;
    cout<<"********MENU********\n";
    cout<<"1.Insert an item\n2.Delete the costliest item\n3.Display\n4.Exit\n";
    while(ch!=4)
    {
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            head=m.getdata(head);
            break;
        case 2:
            head=m.deletee(head);
            break;
        case 3:
            m.display(head);
           break;
       case 4:
            exit(0);
        }
    }
    return 0;
}
