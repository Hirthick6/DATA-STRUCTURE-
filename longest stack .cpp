#include<iostream>
using namespace std;

class node
{
 public:
     int data;
     node* next;
};

void display(node* h)
{
 while(h!=NULL)
 {
  cout<<h->data<<"->";
  h=h->next;
 }
 cout<<"NULL"<<endl;
}

node* createNode(node* h)
{
 node* temp=h;
 int ndata;
 cout<<"Enter element: ";
 cin>>ndata;
 node* nn=new node();
 nn->data=ndata;
 if(temp==NULL)
 {
  nn->next=NULL;
  return nn;
 }
 while(temp->next!=NULL)
 {
  temp=temp->next;
 }
 temp->next=nn;
 nn->next=NULL;
 return h;
}
void longestList(node* h1,node* h2)
{
 node* p1=h1;
 node* p2=h2;
 int count1=0,count2=0;
 while(p1!=NULL)
 {
  count1++;
  p1=p1->next;
 }
 while(p2!=NULL)
 {
  count2++;
  p2=p2->next;
 }
 if(count1==count2)
    cout<<"\nLIST 1 AND LIST 2 ARE EQUAL\n";
 else if(count1>count2)
    cout<<"\nLIST 1 IS THE LONGEST LINKED LIST\n";
 else
    cout<<"\nLIST 2 IS THE LONGEST LINKED LIST\n";
}

int main()
{
 node* p1=NULL;
 node* p2=NULL;
 int n1,n2;
 cout<<"Enter the number of nodes in L1 and L2: ";
 cin>>n1>>n2;
 cout<<"\nFOR LIST L1:\n";
 for(int i=0; i<n1; i++)
    p1=createNode(p1);
 cout<<"\nFOR LIST L2:\n";
 for(int i=0; i<n2; i++)
    p2=createNode(p2);
 cout<<"\nLIST L1:\n";
 display(p1);
 cout<<"\nLIST L2:\n";
 display(p2);
 longestList(p1,p2);
 return 0;
}

