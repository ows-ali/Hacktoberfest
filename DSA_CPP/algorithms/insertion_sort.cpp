#include<iostream>
using namespace std;

void swap(int* a, int* b)	//Swaps two elements of array
{
	int t=*a;
	*a=*b;
	*b=t;
}

int main()
{
	int arr[] = {5,2,4,8,9,1,3,10,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	int j,k;
	for(int i=0;i<n;i++)
	{
		k=i;	//Current element
		j=k+1;	//Element after current

		/*
		The following block keeps swapping elements
		And keeps going backward
		If current is higher than next one
		Till current element is the 1st element
		*/
		while(arr[j]<arr[k] && k>=0)
		{
			swap(&arr[j], &arr[k]);
			j--;
			k--;
		}
	}

	cout<<"Sorted array: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}