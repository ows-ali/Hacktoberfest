#include <iostream>

using namespace std;

void printarray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int diff(int arr[], int size, int n){
    
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j< size-1; j++){
            if(arr[i] - arr[j]== n){
                cout << "(" << arr[i] << "," << arr[j] << ")" << " have difference of" << n << endl;
            }
            else{
                cout << "There is no pair with difference of " << n << endl;
            }
          }
        }
    return 0;
}

int main (){
    int k, N;
    int arr[]={5,8,11,18,20,25,28,29,30,32,34,39,37,46,55,88,97};  
    
    cout << "Array is:";
    printarray(arr, 17);
    cout << endl;
    
    cout << "N(difference): ";
    cin >> N; 
   
    diff(arr, 17, N);
    
    return 0;
}