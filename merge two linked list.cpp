#include<iostream>
using namespace std;
class node
{
    public:
    node*next;
    int data;
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
 if(h==NULL)
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


node* merge(node*head1,node*head2)
{
  node*temp=head1;
  while(temp->next!=NULL)
  {
      temp=temp->next;
  }
  temp->next = head2;
  return head1;
}

node* delduplicate(node* head)
{
 node* temp = head;
 node* p,*cur;

 while(temp!=NULL)
 {
   temp->data;
   cur=head;
   p=cur;
   while(cur!=NULL)
   {
    if(cur->data==temp->data && cur->next!=temp->next)
    {
      p->next = cur->next;
      delete(cur);
      cur = p->next;
    }
    else
    {
      p = cur;
      cur = cur->next;
    }
   }
   temp=temp->next;
 }
 return head;
}

int main()
{
 node* mergeL=NULL;
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

 cout<<"\nMERGED LINKED LIST:\n";
 mergeL = merge(p1,p2);

 mergeL = delduplicate(mergeL);
 display(mergeL);
 return 0;
}
