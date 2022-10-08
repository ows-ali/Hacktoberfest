#include <iostream>
#include <climits>

using namespace std;

int sub_array(int a[], int size){
    int max_here=0, max_so_far = INT_MIN;
    for (int i =0; i < size; i++){
        max_here = max_here + a[i];
        if (max_here > max_so_far){
            max_so_far = max_here;
        }
        else if (max_here < 0){
            max_here = 0 ;
        }
    }
    return max_so_far;
}

int main(){
    int a[]= {0,3,4,5,6,46,6,32,-12,24,91};
    cout << sub_array(a, 11) << endl;
    return 0;
}