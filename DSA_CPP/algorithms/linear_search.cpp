#include<iostream>
using namespace std;

int main()
{
	int arr[] = {2, 3, 1, 10, 7, 6, 5, 9, 4, 8};
	int n = sizeof(arr)/sizeof(arr[0]);

	int x;
	cout<<"Search for: "; cin>>x;

	for(int i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			cout<<"Element found at index "<<i<<endl;
			return 0;
		}
	}

	cout<<"Element not found."<<endl;

	return 0;
}