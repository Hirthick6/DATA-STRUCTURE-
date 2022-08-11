#include<iostream>
using namespace std;
class set
{
public:


    void intersection(int a1[],int a2[],int v,int u)
    {
      cout<<"intersection\n";
      for(int i=0;i<5;i++)
      {
          int temp=0;
          for(int j=0;j<5;j++)
          {
              if(a1[i]==a2[j])
                {
                    temp=1;
                 break;
                }
          }
          if(temp==1)
            cout<<a1[i]<<" ";
      }
    }


void unionu(int a1[],int a2[],int v,int u)
    {
      cout<<"union\n";
      for(int i=0;i<v;i++)
      {
          cout<<a1[i]<<" ";
      }
      for(int i=0;i<v;i++)
      {
          int temp=0;
          for(int j=0;j<u;j++)
          {
              if(a2[i]==a1[j])
                {
                 temp=1;
                 break;
                }
          }
            if(temp==0)
                cout<<a2[i]<<" ";
      }
    }


void difference(int a1[],int a2[],int v,int u)
    {
      cout<<"a-b difference\n";
      for(int i=0;i<v;i++)
      {
          int temp=0;
          for(int j=0;j<u;j++)
          {
              if(a1[i]==a2[j])
                {
                    temp=1;
                 break;
                }
          }
          if(temp==0)
            cout<<a1[i]<<" ";
      }
      cout<<"\nb-a difference\n";
      for(int i=0;i<u;i++)
      {
          int temp=0;
          for(int j=0;j<v;j++)
          {
              if(a1[i]==a2[j])
                {
                    temp=1;
                 break;
                }
          }
          if(temp==0)
            cout<<a2[i]<<" ";;
      }}


void cardinality(int a1[],int a2[],int v,int u)
{
    int c1=0,c2=0;
    cout<<"cardinality of set 1\n";
    for(int i=0;i<v;i++)
    {
        c1+=1;
    }
    cout<<c1;
    cout<<"\ncardinality of set 2\n";
    for(int i=0;i<u;i++)
    {
        c2+=1;
    }
    cout<<c2;
}


void membership(int a1[],int a2[],int v,int u,int e)
{
    int temp;
    for(int i=0;i<v;i++)
    {
        if(a1[i]==e)
            temp=1;
    }
    if(temp==1)
        cout<<"element found in 1st array\n";

    for(int j=0;j<u;j++)
    {
        if(a2[j]==e)
            temp=0;
    }
    if(temp==0)
         cout<<"element found in 2nd array\n";
    }
};

int main()
{
    set s;
    int a1[10],a2[10],i,ip=0,ch,e,v,u;
    cout<<"enter total no of elements in 1st and 2nd array ";
    cin>>v>>u;
    cout<<"enter elements of 1st array ";
    for(i=0;i<v;i++)
    cin>>a1[i];
    cout<<"enter elements of 2nd array ";
    for(i=0;i<u;i++)
    cin>>a2[i];
    while(ip!=6)
    {
        cout<<"\noperations to perform\n1.union\n2.intersection\n3.difference of a-b\n4.cardinality\n5.membership\n6.exit\n";cin>>ch;
        switch(ch)
        {
        case 1:
             s.unionu(a1,a2,v,u);
             break;
        case 2:
             s.intersection(a1,a2,v,u);
             break;
        case 3:
             s.difference(a1,a2,v,u);
             break;
        case 4:
             s.cardinality(a1,a2,v,u);
             break;
        case 5:
            cout<<"enter element to search ";
            cin>>e;
             s.membership(a1,a2,v,u,e);
             break;
        case 6:
             cout<<"the end";
        }
    }
    return 0;
}
