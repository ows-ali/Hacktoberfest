#include <iostream>

using namespace std;

bool subarrayiszero(int a[], int s){
    int req = 0;
    int sum = 0;
    for(int i=0; i<s; i++){
        sum = a[i];
        for(int j = i+1; j<s; j++){
            if (sum == req){
                return true;
            }
            //else if(sum > req){
                //break;
            //}
            else if(j == s){
                break;
            }
            sum = sum + a[j];
        }    
    } 
    return false;
}

int main(){
 int A[] = {4,2,-3,1,6};

 subarrayiszero(A, 5)?
 cout<<"Exists":
 cout<<"Doesn't";

 return 0;
}