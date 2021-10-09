#include <iostream>
using namespace std;

int binSearch(int arr[5], int search){
	int m = 5/2, k = search;
	if(arr[m] == k)
	{
		return m;
	}
	else 
	{
		if(arr[m] > k){
			m = (m + 5) / 2;
			binSearch(arr, k);
		}
		if(arr[m] < search){
			m = (1 + m) / 2;
			binSearch(arr, k);
		}
	}
	return 0;
}
int main(){
	int array[5] = {1,2,3,4,5};
	cout << binSearch(array, 6);
}

