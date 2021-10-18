#include<iostream>
//Recursive approach
//Array should be sorted in ascending order
using namespace std;
int binsearch(int arr[],int ele,int beg,int end){
	if(end>=beg){
		int mid=(beg+end)/2;
		if(arr[mid]==ele)
			return mid;
		else if(arr[mid]<ele)
			beg=mid+1;
		else
			end=mid-1;
		return binsearch(arr,ele,beg,end);
	}
	return -1;
}
int main(){
	const int max = 100;;
	cout<<"Enter the size of your array : ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of your array : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int item;	
	cout<<"Enter the element you want to search for : ";
	cin>>item;
	int pos=binsearch(arr,item,0,n-1);	
	if(pos!=-1)
		cout<<"Element found at index : "<<pos+1;
	else 
		cout<<"Sorry! Element not found";	
	return 0;
}
