#include<iostream>
using namespace std;
class node
{
public:
    int col;
    int data;
    node* next;
    };
class sparsemat
    {
    node* row[10];
    int nrow;
public:
     sparsemat(int n);
    void create_value_node(int rownum,int columnum,int value);
    void sum(int rownum,int value);
    void display();
};
 sparsemat::sparsemat(int n)
{
    for(int j=0;j<n;j++)
    {
        row[j]=NULL;
    }
    nrow=n;
}
 void sparsemat::create_value_node(int rownum,int colnum,int value)
 {
     int sum=0;
     node*nn =new node();
     nn->data=value;
     nn->col=colnum;
     nn->next=NULL;
     if(row[rownum]==NULL)
     {

         row[rownum]=nn;
         return;
     }
     node*t=row[rownum];
     while(t->next!=NULL)
     {
         t=t->next;
     }
     t->next=nn;
      if(t!=NULL)
         {
             sum+=t->data;cout<<sum;
         }
 }
 void sparsemat::sum(int rownum,int value)
 {

     int sum=0;
     for(int i=0;i<nrow;i++)
     {
         node*p=row[i];
        if(row[i]!=NULL)
        {
            while(p!=NULL && p->col!=i)
        {
         p=p->next;
        }
        if(p!=NULL)
         {
             sum+=p->data;
         }
     }
 }
  cout<<"\nsum of diagonal:"<<sum;
 }
 void sparsemat::display()
 {

     cout<<"displayed elements";
     int i,count=0;
     for(i=0;i<nrow;i++)
     {
         cout<<"\n";
         node*t=row[i];
         if (row[i]!=NULL)
        while(t!=NULL)
 {
     count++;
     cout<<"  "<<t->data;
     t=t->next;
 }
 }
 cout<<"\ncount of non zero elements="<<count;
 }
 int main()
 {
 int n,nz,rownum,colnum,value;
 cout<<"enter no.of rows: ";
 cin>>n;
 sparsemat *spmat=new sparsemat(n);
 cout<<"enter no. of non zero elements:";
 cin>>nz;
 for(int i=1;i<=nz;i++)
    {

        cout<<"enter the row , column and value of the element:";
        cin>>rownum>>colnum>>value;
        spmat->create_value_node(rownum,colnum,value);
     }
    spmat->display();
     spmat->sum(rownum,value);
    return 0;
  }
