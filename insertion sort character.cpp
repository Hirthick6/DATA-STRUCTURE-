#include<iostream>
using namespace std;
void insertionSort(char arr[])
{
    int key;
    int j=0;
    for(int i=0;i<5;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main()
{
    char myarr[5];
    cout<<"enter integers\n";
    for(int i=0;i<5;i++)
    {
        cin>>myarr[i];
    }
    cout<<"Unsorted Array"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<myarr[i]<<" ";
    }
      cout << endl;
      insertionSort(myarr);

      cout<<"Sorted array"<<endl;
      for(int i=0;i<5;i++)
    {
        cout<<myarr[i]<<" ";
    }
}


