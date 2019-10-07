//Program to print an array, having n integers, in reverse order.
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n; //Input the number of integers n
    
    int array[n]; //Declaration of array of n size

    for(int i=0; i<n; i++){
        cin>>array[i]; //Write the values in array, that is, store the values in array
    }
    for (int i=n; i>0; i--){
        cout<<array[i-1]<<" ";//Print the values of array in reverse order using cout
    }

    return 0;
}

