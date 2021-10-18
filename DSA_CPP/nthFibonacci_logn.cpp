#include <bits/stdc++.h>
using namespace std;

// helper function to multiply two 2x2 matrices
void multiply(int a[2][2],int m[2][2]){
    int firstValue = a[0][0]*m[0][0] + a[0][1]*m[1][0];
    int secondValue = a[0][0]*m[0][1] + a[0][1]*m[1][1];
    int thirdValue = a[1][0]*m[0][0] + a[1][1]*m[1][0];
    int fourthValue = a[1][0]*m[0][1] + a[1][1]*m[1][1];
    a[0][0] = firstValue;
    a[0][1] = secondValue;
    a[1][0] = thirdValue;
    a[1][1] = fourthValue;
}
// function to compute power of 2x2 matrix using matrix exponentiation
void power(int a[2][2],int n){
    // base case
    if(n==0 || n==1)
        return;
    power(a,n/2);
    multiply(a,a);
    if(n%2!=0){
        int m[2][2] = {{1,1},{1,0}};
        multiply(a,m);
    }
}
int fib(int n){
    int a[2][2] = {{1,1},{1,0}};
    if(n==0)
        return 0;
    // find matrix to the power (n-1)
    power(a,n-1);
    // (0,0) element is the nth fibonacci number
    return a[0][0];
}
int main(){
    // enter n
    int n;
    cin >> n;
    cout << n << "th fibonacci number: " << fib(n);
}