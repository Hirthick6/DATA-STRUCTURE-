#include<iostream>
using namespace std;

class node
{
  public:
  string data;
  node* next;
};

node* insPos1(node* h1,int pos,string new_data)
{
 int count=0;
 node* cur=h1;
 if(pos==1)
 {
  node* newn = new node();
  newn->data = new_data;
  newn->next=cur;
  cur=newn;
  return cur;
 }
 while(cur!=NULL)
 {
  count++;
  if(count==(pos-1))
    break;
  cur=cur->next;
 }
 if(cur==NULL)
 {
  cout<<"Position not found\n"<<endl;
  return h1;
 }
 node* newn = new node();
 newn->data = new_data;
 newn->next = cur->next;
 cur->next = newn;
 return h1;
}
node* insPos2(node* h2,int pos2,string new_data)
{
 int count=0;
 node* cur=h2;
 if(pos2==1)
 {
  node* newn = new node();
  newn->data = new_data;
  newn->next=cur;
  cur=newn;
  return cur;
 }
 while(cur!=NULL)
 {
  count++;
  if(count==(pos2-1))
    break;
  cur=cur->next;
 }
 if(cur==NULL)
 {
  cout<<"Position not found\n"<<endl;
  return h2;
 }
 node* newn = new node();
 newn->data = new_data;
 newn->next = cur->next;
 cur->next = newn;
 return h2;
}
void delPos(node* h,node*h2)
{
 node* cur1=h;
 node*cur2=h2;
 if(cur1==h && cur2==h2 && cur1->data==cur2->data)
 {
  node* del=cur1;
  cur1 = del->next;
  cur1=h;
   delete(del);
  node* del2=cur2;
  cur2 = del2->next;
  cur2=h2;
  delete(del2);
 }
 else

 {
 while(cur1!=NULL && cur2!=NULL && cur1->data==cur2->data)
  {

 node* del=cur1->next;
 cur1->next=cur1->next->next;
 delete(del);
 node* del2=cur2->next;
 cur2->next=cur2->next->next;
 delete(del2);

  }

          cur1=cur1->next;
          cur2=cur2->next;
 }
}


void display(node* h,node*h2)
{
    cout<<"\nelements of first ll:\n";
 while(h!=NULL)
 {
  cout<<h->data<<"->";
  h=h->next;
 }
 cout<<"NULL";
 cout<<"\nelements of second ll:\n";
 while(h2!=NULL)
 {
  cout<<h2->data<<"->";
  h2=h2->next;
 }
 cout<<"NULL";
}




int main()
{
  string new_data;
  int pos,pos2,n;

  node* head = NULL;
  node*head2=NULL;
  while(n!=5)
  {
      cout<<"\n1.Insert\n 2.Deletion\n 3.Display\n"<<endl;
      cout<<"Enter your choice:\t";
      cin>>n;


  switch(n)
  {
  case 1:
  cout<<"\nEnter the position: ";
  cin>>pos;
  cout<<"\nenter elements for first list:\n";
  cin>>new_data;
  head = insPos1(head,pos,new_data);
  cout<<"\nEnter the position: ";
  cin>>pos2;
  cout<<"\nenter elements for second list:\n";
  cin>>new_data;
  head2 = insPos2(head2,pos2,new_data);
  cout<<"\n";
  break;

  case 2:
  delPos(head,head2);
  cout<<"deleted";
  break;

  case 3:
    display(head,head2);
    break;

  default:
    cout<<"exit";

   }
  }

}
