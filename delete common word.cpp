#include<iostream>
#include<string.h>
using namespace std;
class node
{
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
void display(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
void deletecommonword(node*head1,node*head2)
{
    int t=0;
    node*curr=head2,*temp=head1;
    while(head1!=NULL)
    {
        head2=curr;
        while(head2!=NULL)
        {
           if(head1->data==head2->data)
           {
               t=1;
              if(head2->prev==NULL)
              {
                  curr=head2->next;
                  curr->prev=NULL;
              }
              else
              {
                  head2->prev->next=head2->next;
                  head2->next->prev=head2->prev;
              }
           }
           head2=head2->next;
        }
        if(t==1)
        {
            if(head1->prev==NULL)
            {
                head1=head1->next;
                head1->prev=NULL;
            }
            else
            {
                head1->prev->next=head1->next;
                head1->next->prev=head1->prev;
            }
        }
        head1=head1->next;
        t=0;
        }
    }

int main()
{
   int i;
   string st1,st2,word="";
   char ch;
   node*head1=NULL;
   node*head2=NULL;
   cout<<"Enter string 1 : ";
   getline(cin,st1);
   cout<<"Enter string 2 : ";
   getline(cin,st2);
   st1=st1+" ";
   st2=st2+" ";
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
   word="";
   for(i=0;i<st2.length();i++)
   {
      ch=st2.at(i);
       if(ch!=' ')
        word=word+ch;
       else
        {
         head2=getdata(head2,word);
       word="";
       }
   }

   display(head1);
   display(head2);
   deletecommonword(head1,head2);
   cout<<endl;
    display(head1);
   display(head2);

}
