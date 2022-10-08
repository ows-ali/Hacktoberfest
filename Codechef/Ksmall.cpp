#include <iostream>

using namespace std;

void printarray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int bubble_sort(int arr[], int size){
    int temp;
    for(int i = 0; i < size; i++){
        for(int j = 0; j< size; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return 0;
}

int kthelement(int arr[], int n, int k){
    bubble_sort(arr, n);
    return arr[n-k];

}

int main (){
    int k;
    int arr[]={3,2,21,4,44,5,7,5,64,66,6,6,4,4,4,54,5};  

    cout << "Array is:";
    printarray(arr, 17);
    cout << endl;
    
    cout << "Kth be: ";
    cin >> k;
   
    cout << k << " element is: " << kthelement(arr, 17, k) << endl;
    
    return 0;
}