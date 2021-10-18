//Fatima Mubeen
//Array Sorting algos Source file
#include<iostream>
using namespace std;

class sort{
	int *arr,size;
public:
	
	//constructor
	sort(){
		arr = NULL;
		size = 0;
	}
	
	//parametrized constructor
	sort(int *&a, int s){
		arr = a;
		size = s;
	}
	
	//Setter function for array
	void setArray(int *&a,int s){

		arr = a;
	}
	
	//Setter function for array size
	void setSize(int s){
		size = s;
	}
	
	//Getter function for array
	int* getArray(){
		return arr;
	}
	
	//Getter function for array size
	int getSize(){
		return size;
	}
	
	//Print function for array
	void printArray(){
		cout << endl << "Array is :  ";
		for (int i = 0; i < size; i++){
			cout << arr[i] << " ";
		}
	}
	
	//Bubble sort (ascending) algo function for array
	void bubbleSort(){
		for (int i = 0; i < size; i++)
		{
			int t = 0;
			for (int j = 1; j < size - i; j++)
			{
				if (arr[j - 1]>arr[j])
				{
					t = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = t;
				}
			}
		}
	}
	
	//Selection sort (ascending) algo function for array
	void selectionSort(){
		int min, minIndex;
		for (int i = 0; i <size; i++)
		{
			min = arr[i]; minIndex = i;
			for (int j = i + 1; j < size ; j++)
			{
				if (arr[j] < min)
				{
					min = arr[j]; minIndex = j;
				}
			}
			arr[minIndex] = arr[i];
			arr[i] = min;
		}
	}
	
	//insertion sort (ascending) algo function for array
	void insertionSort(){
		int i, j , t;
		for (i = 1; i < size; i++)
		{
			t = arr[i];
			for (j = 0; j < i; ++j) 
			{
				if (t < arr[j])  
					break;
			}
			for (int m = i; m>j; m--) 
			{
				arr[m] = arr[m - 1]; 
			}
			arr[j] = t;
		}
	}

};

int main(){
	int *a, s;
	cout << "Enter Size of Array :";
	cin >> s;
	a = new int[s];
	cout << "Enter Array Elements : "<<endl;
	for (int i = 0; i < s; i++){
		cout <<"Element "<<i+1<<" : ";
		cin >> a[i];
	}
	sort SORT(a, s);
	cout << "Before Sorting ";
	SORT.printArray();
	cout << endl<< "After Sorting ";
	//SORT.bubbleSort();					//you can call any sorting algo here I have called inserstion and commented others
	//SORT.selectionSort();
	SORT.insertionSort();
	SORT.printArray();

	return 0;

}
