#include<iostream>
using namespace std;

class node
{
  public:
  string name,name2;
  long int phno,phno2;
  node* next;
  node*prev;
node* insPos(node* h,int pos1,long int phno,string name)
{
 int count=0;
 node* cur=h;
 if(pos1==1)
 {
  node* newn = new node();
  newn->name = name;
  newn->phno=phno;
   newn->next=NULL;
    newn->prev=NULL;

    newn->next=cur;

    cur=newn;
    return cur;
 }
 while(cur!=NULL)
 {
  count++;
  if(count==(pos1-1))
    break;
  cur=cur->next;
 }
 if(cur==NULL)
 {
  cout<<"Position not found\n"<<endl;
  return h;
 }
 node* newn = new node();
  newn->name = name;
  newn->phno=phno;
   newn->next=NULL;
    newn->prev=NULL;
        cur->next=newn;
        newn->prev=cur;
        return cur;

}
node* insPos2(node* h2,int pos2,long int phno2,string name2)
{
 int count=0;
 node* cur=h2;
 if(pos2==1)
 {
  node* newn = new node();
  newn->name2= name2;
  newn->phno2=phno2;
   newn->next=NULL;
    newn->prev=NULL;
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
  newn->name2 = name2;
  newn->phno2=phno2;
   newn->next=NULL;
    newn->prev=NULL;
        cur->next=newn;
        newn->prev=cur;
        return h2;

}
void display(node* h,node*h2)
{
    cout<<"\n contact details of family 1 members:\n";
 while(h!=NULL)
 {
  cout<<"name :"<<h->name<<"\n";
  cout<<"ph.no :"<<h->phno<<"\n";
  h=h->next;
 }
 cout<<"\ncontact details of family 2 members:\n ";
 while(h2!=NULL)
 {
  cout<<"name :"<<h2->name2<<"\n";
  cout<<"ph.no :"<<h2->phno2<<"\n";
  h2=h2->next;
 }
}
};
int main()
{
  long int pos,pos2,n,phno,phno2;
  string name,name2;
  node*h = NULL;
  node*h2=NULL;
  node*j;
  while(5)
  {cout<<"linked list operations\n1.Insertion\n2.Display\n";
  cout<<"Enter your choice:\t";
  cin>>n;
  switch(n)
  {
  case 1:
    cout<<"\nenter dtails for family 1\n";
     cout<<"enter the name of member:";
     cin>>name;
     cout<<"enter the ph.no:";
     cin>>phno;
     cout<<"enter the position:";
     cin>>pos;
     h=j.insPos(h,pos,phno,name);
     cout<<"\nenter dtails for family 2\n";
     cout<<"enter the name of member:";
     cin>>name2;
     cout<<"enter the ph.no:";
     cin>>phno2;
     cout<<"enter the position:";
     cin>>pos2;
     h2=j.insPos2(h2,pos2,phno2,name2);
    break;

  case 2:
    j.display(h,h2);
    break;

  }
  }
}
