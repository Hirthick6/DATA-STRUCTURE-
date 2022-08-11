#include<iostream>
#include<conio.h>
#define max 50
int stack1[max],top1=-1;
int stack2[max],top2=-1;
int temp[max],t=-1;
void create()
{
char ch;
do
{
top1++;
cout<<"Enter Number\n";
cin>>stack1[top1];
cout<<"Continue(y/n)\n";
ch=getch();
}while(ch=='y');
}

void traverse1()
{
int i;
cout<<"First Stack is :\n";
for(i=top1;i>=0;i--){
cout<<stack1[i];
}
}
void traverse2()
{
int i;
printf("Second Stack is :\n");
for(i=top2;i>=0;i--)
{
cout<<stack2[i];
}
}

void copy()
{
int i;
for(i=top1;i>=0;i--)
{
t++;
temp[t]=stack1[i];
}
for(i=t;i>=0;i--)
{
top2++;
stack2[top2]=temp[i];
}
}
int main()
{
create();
traverse1();
copy();
traverse2();
return 0;
}
