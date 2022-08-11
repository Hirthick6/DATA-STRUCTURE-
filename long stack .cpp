#include<iostream>
using namespace std;
class node
{
public:

  int data;
  node*next;
};
void display(node*h)
{
      while(h!=NULL)
      {
          cout<<h->data<<" ->";
          h=h->next;
      }
      cout<<"NULL  ";

}

node* create(node*h)
{
    node*t=h;
    int ele;
    cout<<"enter number";
    cin>>ele;
    node*nn=new node();
    nn->data=ele;

    if(h==NULL)
    {
        nn->next=NULL;
        return nn;

    }
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=nn;
    nn->next=NULL;
    return h;
}

void longll(node*l1,node*l2)
{
    node*t1=l1;
    node*t2=l2;
    int count1=0,count2=0;
    while(t1!=NULL)
    {
        count1++;
        t1=t1->next;
    }
    while(t2!=NULL)
    {
        count2++;
        t2=t2->next;
    }
    if(count1==count2)
    {
        cout<<"equal";
    }
    else if(count1>count2)
    {
        cout<<"\n1 st stack is long";
    }
    else
    {
         cout<<"\n2 nd stack is long";
    }
}
int main()
{
    node*t1=NULL;
    node*t2=NULL;
    int n1,n2;
    cout<<"enter L1 and L2";
    cin>>n1>>n2;
    cout<<"\n list 1\n";
    for(int i=0;i<n1;i++)
    {
        t1=create(t1);
    }
     cout<<"\n list 2\n";
    for(int i=0;i<n2;i++)
    {
        t2=create(t2);
    }
    cout<<"\nLIST L1:\n";
 display(t1);
 cout<<"\nLIST L2:\n";
 display(t2);
 longll(t1,t2);
 return 0;
}
