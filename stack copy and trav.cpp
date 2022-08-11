#include<iostream>
using namespace std;
class stk
{
public:
    int stack1[50];
    int stack2[50];
    int temp[50];
    int top1;
    int top2;
    int t;
    stk ()
    {
         top1=-1;
         top2=-1;
         t=-1;
    }
    create();
    traverse1();
    traverse2();
    copys();
};
int stk::create()
{
    int ch;
    do
    {
    top1++;
    cout<<"enter stack1";
    cin>>stack1[top1];
    cout<<"\nContinue(y/n)\n";
    cin>>ch;
    }while(ch=='y');
}
int stk::traverse1()
{
    int i;
    cout<<"stack1";
    for(i=top1;i>=0;i--)
    {
        cout<<stack1[i];
    }
}
int stk::traverse2()
{
    int i;
    cout<<"stack2";
    for(i=top2;i>=0;i--)
    {
        cout<<stack2[i];
    }
}
int stk::copys()
{
     int i;int t1;
      for(i=top1;i>=0;i--)
      {
          t++;
          temp[t]=stack1[t1++];
      }
      for(i=t;i>=0;i--)
      {
          top2++;
        stack2[top2]=temp[i];
      }

}

int main()
{
    stk s;
    s.create();
    s.traverse1();
     s.traverse2();
    s.copys();
}
