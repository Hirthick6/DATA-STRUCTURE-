#include<iostream>
using namespace std;
int main()
{
int arr1[10], arr2[10],i,j,m,n;
    cout<<"Enter size of array 1 and array 2 respectively (less than 10)"<<endl;
    cin>>m>>n;
    cout<<"Enter elements of set 1"<<endl;
    for(i=0;i<m;i++)
    cin>>arr1[i];
    cout<<"Enter elements of set 2"<<endl;
    for(j=0;j<n;j++)
    cin>>arr2[j];

    cout<<"DIFFERENCE (A-B):";
    for(i=0;i<m;i++)
    {
     int k=0;
     for(j=0;j<n;j++)
       {
        if(arr1[i]==arr2[j])
          {
           k=1;
           break;
          }
        }
        if(k==0)
          {
           cout<<arr1[i]<<" ";
          }

       }



       cout<<endl;

    cout<<"DIFFERENCE (B-A):";
    for(i=0;i<m;i++)
    {
     int k=0;
     for(j=0;j<n;j++)
       {
        if(arr1[j]==arr2[i])
          {
           k=1;
           break;
          }
        }
          if(k==0)
          {
           cout<<arr2[i]<<" ";
          }
          if(n>m)
          {
            cout<<arr2[i]<<endl;
          }


       }

       cout<<endl;

return 0;


}
