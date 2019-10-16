#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    const char* arr[] = {"one","two","three","four","five","six","seven","eight","nine"};
    int a;
    int b;
    cin >>a >>b;
    for (int i = a; i<=b ;i++){
        if (i <=9){
            printf(arr[i-1]);
            printf("\n");
        }
        else if (i > 9 && i % 2 == 0){
            printf("even\n");
        }
        else{
            printf("odd\n");
        }
    }
    return 0;
}
