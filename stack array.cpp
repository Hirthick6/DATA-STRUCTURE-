#include<iostream>
using namespace std;
#define MAX 100;
class stack
{
    int top;
public:
    int a[100];
    stack()
    {
        top=-1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isempty();
    void display();
};
bool stack::push(int x)
{
    if(top>=(100-1))
    {
        cout<<"stack overflow";
        return false;
    }
    else
    {
        a[++top]=x;
        cout<<x<<endl;
        return true;
    }
}
int stack::pop()
{
    int x;
    if(top<0)
    {
        cout<<"underflow";
        return 0;
    }
    else
    {
        x=a[top--];
        return x;
    }
}
int stack ::peek()
{
    if(top<0)
    {
        cout<<"underflow";
        return 0;
    }
    else
    {
        int x=a[top];
        return x;
    }
}
bool stack :: isempty()
{
    return (top<0);
}
void stack:: display()
{
 if(top>=0)
{
 cout<<"Stack elements are:";

 for(int i=top; i>=0; i--)
 cout<<a[i]<<" ";
 cout<<endl;
 }
 else
 {
 cout<<"Stack is empty";
 }
}

int main()
 {
 int ch, x;
 stack s;
 cout<<"1) Push in stack"<<endl;
 cout<<"2) Pop from stack"<<endl;
 cout<<"3) Peek from stack"<<endl;
 cout<<"4) isempty stack"<<endl;
 cout<<"5) Display stack"<<endl;
 cout<<"6) Exit"<<endl;

 do {

 cout<<"Enter choice: "<<endl;
 cin>>ch;
 switch(ch)
  {
 case 1: {
 cout<<"Enter value to be pushed:"<<endl;
 cin>>x;
 s.push(x);
 break;
 }
 case 2:
  {
 cout<<s.pop()<<"popped value"<<endl;
 break;
 }

case 3:
{
       cout<< s.peek()<<"peek value"<<endl;
        break;
}

 case 4:
    {
       s.isempty();
        break;
    }
 case 5: {
 s.display();
 break;
 }
 case 6: {
 cout<<"Exit"<<endl;
 break;
 }
 default: {
 cout<<"Invalid Choice"<<endl;
 }
 }
 }while(ch!=6);
 return 0;
}
