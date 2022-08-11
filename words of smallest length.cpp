//contains the word of smallest length.
#include<iostream>
#include<string.h>
using namespace std;
class node{
public:
    string data;
    node*next;
    node*prev;
};
node* getdata(node*head,string word)
{
   node*nn=new node();
   nn->data=word;
   nn->next=NULL;
   if(head==NULL)
   {
    head=nn;
    nn->prev=NULL;
   }
   else
   {
      node*curr=head;
      while(curr->next!=NULL)
      curr=curr->next;
      curr->next=nn;
      nn->prev=curr;
   }
   return head;
}
void delsmallword(node*head)
{
    int min=head->data.length();
    node*temp=head->next;
    while(temp!=NULL)
    {
        if(temp->data.length()<min)
            min=temp->data.length();
            temp=temp->next;
    }
    temp=head;
    while(head!=NULL)
    {
        if(head->data.length()==min)
        {
           if(head->prev==NULL)
           {
               head->next->prev=NULL;
               temp=head->next;
           }
           else
           {
               head->prev->next=head->next;
               head->next->prev=head->prev;
           }
        }
        head=head->next;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
   int i;
   string st1,st2,word="";
   char ch;
   node*head1=NULL;
   cout<<"Enter string 1 : ";
   getline(cin,st1);
   st1=st1+" ";
   for(i=0;i<st1.length();i++)
   {
       ch=st1.at(i);
       if(ch!=' ')
        word=word+ch;
       else
        {
       head1=getdata(head1,word);
       word="";
       }
   }

  delsmallword(head1);
}
