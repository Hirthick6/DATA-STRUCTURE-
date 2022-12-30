#include <iostream>
using namespace std;
template <typename T>
void selection_sort(T arr[],int n)
{
for(int i=1;i<n;i++)
{
    int min=i;
for(int j=i+1;j<n;j++)
{
    if(arr[j]<arr[min])
    {
        min=j;
    }
}
if(min!=i)
{
      int temp=arr[min];
    arr[min]=arr[i];
    arr[i]=temp;
}
}
}
template <typename T>
int bin_search(T arr[],int n ,T x)
{
    int start = 0;
    int end = n-1;
    while(start <= end)
    {
        int mid = (start+end)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] < x)
            start = mid +1;
        else
            end = mid -1;
    }
    return -1;
}

int main()
{
   cout << "Enter number of Elements in Array\n   ";
   int n;
   cin >> n;
   int arr[n];
   cout << "\nEnter Elements of Array\n   ";

   for(int i = 0;i < n ; i++)
   {
       cin >> arr[i];
   }

   selection_sort<int>(arr,n);

   cout << "Enter Element to Search\n   ";
   int x;
   cin >> x;

   cout << "\nIndex is:"<<bin_search<int>(arr,n,x);
   cout << "\nPosition is:"<<bin_search<int>(arr,n,x)+1;
}
