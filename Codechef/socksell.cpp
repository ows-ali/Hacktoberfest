#include<iostream>

using namespace std;

int operation(int a[], int size){
    int max, gmax = 0 , j;
    for(int i=0; i < size; i++){
        for(j=i+1; j<size; j++){
            if (a[i] > a[j]){
                max = (a[i] - a[j]);
            }
            if (max > gmax){
                gmax = max;
            }
        }
        if (gmax == 0){
            return 0;
        }


    } 
    return j;
}

int main(){
    int arr[] = {7,1,5,3,6,4};

    cout<< operation(arr, 6) << endl;

    return 0;
}