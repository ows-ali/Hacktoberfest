#include<bits/stdc++.h>

void counting_sort(int A[],int size){

    int count[size]={0};
    int output[size];
    for(int i=0;i<size;i++){
        count[A[i]]++;     //Create count array
    }
    for(int i=1;i<size;i++){
        count[i]+=count[i-1];
    }

    for(int i=0;i<size;i++){
        output[count[A[i]]-1] = A[i];  //Sorting operation
        count[A[i]]--;
    }

    for(int j=0;j<size;j++){
        A[j]=output[j];    //Copy the output to the original array
    }
}

int main(){
    int A[]={5,4,3,9,1,4,7,8,2};
    counting_sort(A,9);
    return 0;
}

//This happens in linear time complexity
