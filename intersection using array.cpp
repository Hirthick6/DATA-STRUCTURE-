#include <bits/stdc++.h>
using namespace std;

void printIntersection(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (arr1[i] < arr2[j])
			i++;
		else if (arr2[j] < arr1[i])
			j++;
		else
		{
			cout << arr2[j] << " ";
			i++;
			j++;
		}
	}
}

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
    cout<<"INTERSECTION:"<<endl;
	printIntersection(arr1, arr2, m, n);

	return 0;
}
