#include <iostream>
using namespace std;

template <typename T>
int lin_search(T arr[],int n ,T x)
{
    for(int i = 0; i < n ; i++)
        if(arr[i] == x)
         return i;
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

   cout << "Enter Element to Search\n   ";
   int x;
   cin >> x;

   cout << "\nIndex is:"<<lin_search<int>(arr,n,x);
   cout << "\nPosition is:"<<lin_search<int>(arr,n,x) + 1;
}

