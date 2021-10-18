#include<iostream>
using namespace std;

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};	//Sorted array
	int n = sizeof(arr)/sizeof(arr[0]);

	int e;
	cout<<"Enter element to find: "; cin>>e;

	int f=0, l=n-1;

	int m;

	while(f<=l)	//Will run till 1 element left
	{
		m = (f+l)/2;
		if(e==arr[m])
		{
			cout<<"Element found at index "<<m<<endl;
			return 0;
		}
		if(e<arr[m])	//accessing left half
			l=m-1;
		else if(e>arr[m])	//accessing right half
			f=m+1;
	}
	cout<<"Element not found."<<endl;
}