#include <bits/stdc++.h> 
using namespace std;

int binarySearch(int a[10], int n, int e)
{
	int f = 0, l = n-1;
	int mid;

	while(f <= l)
	{
		mid = (f+l)/2;
		
		if(a[mid] == e)
			return mid;

		else if(a[mid] > e)
			l = mid-1;

		else
			f = mid+1;		
	}

	return -1;


}

int main()
{
	int n =10, e;
	int a[10];
	cout << "Enter a sorted list of 10 numbers";

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cout << "Element to be searched: ";
	cin >> e;

	int res = binarySearch(a,n,e);
	if( res > -1)
		cout << "Element found at "<<res;
	else
		cout << "Element not found.";
	
	return 0;
}