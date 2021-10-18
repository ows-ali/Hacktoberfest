#include <iostream>
using namespace std;

int fib(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int fib2(int n, int* arr){
    if(n == 0 || n == 1){
        return 1;
    }

    if(arr[n] > 0){
        return arr[n];
    }

    int output = fib2(n-1, arr) + fib2(n-2, arr);
    arr[n] = output;

    return output;
}

int main(){
    int n;
    cin >> n;

    int * arr = new int[n+1];
    for(int i=0;  i<n+1; i++){
        arr[i] = 0;
    }

    for(int i=0; i<n; i++){
        cout << i << " : " << fib2(i, arr) << "\n";	
    }

}
