#include<iostream>
using namespace std;

void swap(int* a, int* b)	//swapping two array elements
{
	int t = *a;
	*a = *b;
	*b = t;
}

/*
Following function chooses first element as pivot
Puts all smaller element before pivot
And puts all larger elements after pivot
*/
int partition(int arr[], int f, int l)
{
	int pivot = f; //first element of array
	f++; //f goes to an element after pivot

	while(f<=l)
	{
		while(arr[f]<=arr[pivot])
			f++;
		while(arr[l]>arr[pivot])
			l--;
		if(f<l)
		{
			swap(&arr[f],&arr[l]);
		}
	}
	swap(&arr[pivot], &arr[l]);
	return l;
}

/*
Following function recursively calls itself
After dividing the array in sub-arrays
*/
void quick_sort(int arr[],int f, int l)
{
	if(f<l)
	{
		int pi = partition(arr, f, l);	//Sets the pivot to appropriate location

		quick_sort(arr, f, pi-1);	//Recursive for sub-array before pivot
		quick_sort(arr, pi+1, l);	//Recursive for sub-array after pivot
	}
}

int main()
{
	int arr[] = {1, 5, 2, 4, 10, 8, 7, 9, 3, 6};
	int n = sizeof(arr)/sizeof(arr[0]);

	quick_sort(arr, 0, n-1);

	cout<<"Sorted array: "<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	
	cout<<endl;

	return 0;
}