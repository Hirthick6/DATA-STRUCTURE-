#include<iostream>
using namespace std;
class node
{
public:
    string data;
    int len;
    node*next;
};
node*insert(node*head,string data,int len)
{
    node*nn=new node();
    nn->data=data;
    nn->len=len;
    nn->next=NULL;
    if(head==NULL)
    {
        head=nn;
        return head;
    }
    node*temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    nn->next=temp->next;
    temp->next=nn;
    return head;
}
node* delsmall(node*head)
{
    node*temp=head;
    int min;
    while(temp!=NULL)
    {
        if(temp->len<min)
            min=temp->len;
        temp=temp->next;
    }
    node*t=head;
    node*cur=t;
    while(t!=NULL)
    {
        if(t->len==min)
        {
            if(t==head)
            {
                node*cur2=t;
                t=t->next;
                cur=t;
                head=head->next;
                delete cur2;
            }
            else
            {
                cur->next=t->next;
                delete t;
            }
        }
        else
            cur=t;
        t=t->next;
    }
    return head;
}
void display(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    string data;
    int len;
    node*head=NULL;
    for(int i=0;i<5;i++)
    {
        cout<<"ENTER FIVE ELEMENTS : "<<endl;
        cin>>data;
        len=data.length();
        head=insert(head,data,len);
    }
    cout<<endl;
    display(head);
    cout<<"AFTER DELETING : "<<endl;
    head=delsmall(head);
    display(head);
}
