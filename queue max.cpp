#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
int data;
Node *next;
};
Node *front = 0;
Node *rear = 0;
//check if queue is empty or not
bool isempty()
{
if(front == NULL && rear == NULL)
return true;
else
return false;
}
//enter elements in queue
Node* insert( int value )
{
Node *nn = new Node();
nn->data= value;
nn->next = NULL;
if( front == NULL )
{
front = nn;
rear = nn;
return nn;
}
else
{
rear ->next = nn;
rear = nn;
return nn;
}
}
void max()
{
 if(front==NULL)
 {
     cout<<"NONE";
 }
 else
    {
        node* max=front;
 node* t=front;
    while(t!=NULL)
    {
        if(max->data<t->data
           max=t;
        t=t->next;
    }
    cout<<max->data;
    }
}

}
void del( )
{
if(isempty())
cout<<"Queue is empty\n";
else{
if( front == rear)
{
delete(front);
front = rear = NULL;
}
else
{
Node *t = front;
front = front->next;
delete(t);
}
}
}
void show( )
{
if( isempty())
cout<<"Queue is empty\n";
else
cout<<"element at front is:"<<front->data;
}

void display()
{
if (isempty())
cout<<"Queue is empty\n";
else
{
Node *t = front;
while( t !=NULL)
{
cout<<t->data<<" ";
t= t->next;
}
}
}
int main()
{
    Node*front;
int choice, flag=1, value;
while( flag )
{
cout << endl <<"1. Enter queue" << endl << "2. Delete queue" << endl <<"3. Show Front" << endl << "4. Display queue" << endl << "5. Exit" << endl;
cin>>choice;
switch (choice)
{
case 1: cout<<"Enter Value:\n";
cin>>value;
insert(value);
break;
case 2: del();
break;
case 3: show();
break;
case 4: display();
cout<<"max function:"<<max();
break;
case 5: flag = 0;
break;
}
}
return 0;
}
