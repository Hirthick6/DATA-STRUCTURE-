#include<iostream>
#define SIZE 10
using namespace std;
class linear
{
   public:
       int h;
       int a[n];
       int size;
       linear()
       {
        size = 0;
        for(int i=0;i<n;i++)
            a[i]=0;
       }

       void display()
        {
         cout<<"\n\nHASH TABLE:\n";
         for(int i=0;i<n;i++)
            cout<<a[i]<<endl;
         cout<<endl;
        }

       void insert()
       {
           if(size>=n){
              cout<<"HASH TABLE FULL"<<endl;
              return;}
           int key;
           cout<<"\nEnter Element: ";
           cin>>key;
           for(int i=0;i<n;i++)
           {
            int index=(key+i*i)%SIZE;
            if(a[index]==0)
            {
             a[index]=key;
             break;
            }
           }
           cout<<"Element entered";
           size++;
           display();
        }

        void search()
        {
         int flag = 0;
         int data;
         cout<<"Enter the element you want to search: ";
         cin>>data;
         for(int i=0;i<n;i++)
         {
           int index=(data+i*i)%n;
           if(a[index]==data)
           {
             flag=1;
             cout<<"ELEMENT "<<data<<" FOUND AT INDEX "<<index<<endl;
           }
         }
         if(flag==0)
            cout<<"ELEMENT "<<data<<" NOT FOUND"<<endl;
        }

};

int main()
{
  linear l;
  int choice;
  while(1)
  {
    cout<<"\n---------HASH-----------";
    cout<<"\n1.INSERT\n2.SEARCH\n3.EXIT\n\n";
    cout<<"Enter choice: ";
    cin>>choice;
    switch(choice)
    {
     case 1:
         l.insert();
         break;

     case 2:
         l.search();
         break;

     case 3:
         return 0;
    }
  }
}
