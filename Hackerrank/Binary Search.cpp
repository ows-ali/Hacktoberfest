///////////////////////////////////
// BinarySearch Algorithm 
// for Sorted Array
///////////////////////////////////

// 1-We begin with the mid element of array and use it as a search key.
// 2-If the value of the search key is equal to the item 
// then return an index of the search key OR
// 3-If the value of the search key is less than the item in the middle of the interval,
// narrow the interval to the lower half.

// 4-Otherwise, narrow it to the upper half.
// 5-Repeatedly check from the second point until the value is found 
// or the interval is empty.

// Binary Search Algorithm can be implemented in the following two ways
// 1-Iterative Method
// 2-Recursive Method

// The code below is using the Recursive method
#include<bits/stdc++.h>
using namespace std;
//funtion for implementing binary search
int binarySearch(int *input,int beg,int end,int number){
    if(beg>end){
        return -1;
    }

    // get the mid element of the array
    int mid = (beg+end)/2;

    // if the mid element is equal to the item
    // then return the index of the item
    if(number == input[mid]){
        return mid;
    }
    
    //if the value of the search key is less than the item in the middle of the interval
    //narrow the interval to the lower half
    if(number<input[mid]){
        return binarySearch(input,beg,mid-1,number);
    }
    //Otherwise, narrow it to the upper half.
    else{
        return binarySearch(input,mid+1,end,number);
    }
    
    return -1;
}
//main funtion for calling and control
int main(){
    //Size of The Array
    int n,number;
    cin>>n;
    // Create An array Of size n Dynamically
    int *input = new int[n];
    //Take Input Array in Ascending Order
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    //Take number to be searched
    cin>>number;
    //call the recursive function
    int index = binarySearch(input,0,n-1,number);
    if(index!=-1){
        cout<<number<<" is found at index: "<<index<<endl;
    }else{
        cout<<number<<" not found"<<endl;
    }
    return 0;
}
