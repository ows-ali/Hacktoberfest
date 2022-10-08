#include <iostream>

using namespace std;

int main(){

    int a[] = {1,5,7,1}, size=4, N=6, o=0;

    for(int i=0; i < size; i++){
        for(int j=i+1; j<size; j++){
            if (a[i] + a[j] == N){
            o++;
            }
        }
    }


    cout << "No. of pairs is " << o << endl;

    return 0;
}