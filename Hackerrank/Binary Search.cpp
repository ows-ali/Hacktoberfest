#include<bits/stdc++.h>
using namespace std;
//funtion for implementing binary search
int binarySearch(int *input,int beg,int end,int number){
    if(beg>end){
        return -1;
    }
    int mid = (beg+end)/2;
    if(number == input[mid]){
        return mid;
    }
    //Search left sub array
    if(number<input[mid]){
        return binarySearch(input,beg,mid-1,number);
    }
    //Search right sub array
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
