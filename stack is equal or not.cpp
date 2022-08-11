#include<iostream>
using namespace std;

class node
{
  public:
    int data;
    node* next;
};

node* push(node* h)
{
  int elem;
  if(h==NULL)
  {
    cout<<"Enter element: ";
    cin>>elem;
    node* nn = new node();
    nn->data = elem;
    return nn;
  }
  cout<<"Enter element: ";
  cin>>elem;
  node* nn = new node();
  nn->data = elem;
  nn->next = h;
  return nn;
}

node* pop(node* h)
{
  if(h==NULL)
  {
    cout<<"CANNOT DELETE\n";
    return h;
  }
  node* t = h->next;
  delete(h);
  return t;
}

bool isEqual(node* l1, node* l2)
{
  node *t1=l1, *t2=l2;
  int c1=0,c2=0;
  while(l1!=NULL)
  {
    c1++;
    l1=l1->next;
  }
  while(l2!=NULL)
  {
    c2++;
    l2=l2->next;
  }
  if(c1!=c2)
    return false;
  while(t1!=NULL && t2!=NULL)
  {
    if(t1->data!=t2->data)
        return false;
    t1=t1->next;
    t2=t2->next;
  }
  return true;
}

void display(node* h)
{
    if(h==NULL)
     cout<<"NO ELEMENTS\n";
    else
    {
      while(h!=NULL)
      {
        cout<<"["<<h->data<<"]"<<endl;
        h=h->next;
      }
    }
}

int main()
{
  node* stack1 = NULL;
  node* stack2 = NULL;
  int input=0,choice,n;
  while(input!=4)
  {
    cout<<"\n------ STACK OPERATIONS------\n";
    cout<<"\n1.Push\n2.Pop\n3.IsEqual\n4.Exit\n";
    cout<<"\nEnter the operation: ";
    cin >> choice;
    switch(choice)
    {
      case 1:
          cout<<"\n1->Stack1\n2->Stack2\n";
          cout<<"Enter Choice:";
          cin>>n;
          if(n==1)
          {
            stack1 = push(stack1);
            cout<<"STACK 1:\n";
            display(stack1);
          }
          if(n==2)
          {
            stack2 = push(stack2);
            cout<<"STACK 2:\n";
            display(stack2);
          }
          break;

      case 2:
          cout<<"\n1->Stack1\n2->Stack2\n";
          cout<<"Enter Choice:";
          cin>>n;
          if(n==1)
          {
            stack1 = pop(stack1);
            cout<<"STACK 1:\n";
            display(stack1);
          }
          if(n==2)
          {
            stack2 = pop(stack2);
            cout<<"STACK 2:\n";
            display(stack2);
          }
          break;

      case 3:
          if(isEqual(stack1,stack2))
               cout<<"STACK 1 AND STACK 2 ARE EQUAL\n";
          else
               cout<<"STACK 1 AND STACK 2 ARE NOT EQUAL\n";
          break;

      case 4:
          cout<<"\nProgram Ended\n";
          return 0;;
    }
  }
}
