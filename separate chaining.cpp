#include<iostream>
#include<stdlib.h>
using namespace std;
#define m 10
class node
{
public:
    int data;
    node*next;
};
class hashtable
{
public:
    node* hashh[m];
    hashtable()
    {
        for(int i=0;i<m;i++)
        hashh[i]=NULL;
    }
    node*head;
    void insertt(int);
    void display();
    void searchh(int);
};
void hashtable::insertt(int elem)
{
    int index;
    index=elem%m;
    if(hashh[index]==NULL)
            {
                node*head=new node();
                head->data=elem;
                head->next=NULL;
                hashh[index]=head;
                return;
            }
    node*temp=hashh[index];
    while(temp->next!=NULL)
        temp=temp->next;
    node*nn=new node();
    nn->data=elem;
    nn->next=NULL;
    temp->next=nn;
}
void hashtable::display()
{
    cout<<"\nELEMENTS ARE: ";
    for(int i=0;i<m;i++)
    {
        cout<<"\nROW "<<i;
        node*temp=hashh[i];
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
void hashtable::searchh(int elem)
{
    int c=0,index;
    index=elem%m;
    node*temp=hashh[index];
        while(temp!=NULL)
        {
            if(temp->data==elem)
            {
                cout<<"\nELEMENT FOUND IN HASH INDEX "<<index;
                c=1;
                return;
            }
            temp=temp->next;
        }
    if(c==0)
        cout<<"\nELEMENT NOT FOUND!";
}
int main()
{
    int elem,ch;
    hashtable h;
    while(ch!=3)
    {
        cout<<"\n1.INSERT\n2.SEARCH\n3.EXIT";
        cout<<"\nENTER YOUR CHOICE :";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nENTER 5 ELEMENTS TO INSERT : ";
            for(int i=0;i<5;i++)
           {
                 cin>>elem;
                 h.insertt(elem);

           }
            h.display();
            break;
        case 2:
            cout<<"ENTER ELEMENT TO SEARCH : ";
            cin>>elem;
            h.searchh(elem);
            break;
        case 3:
            exit(0);

        }
    }
}
