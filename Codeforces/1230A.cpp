#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int arr[4];
    int sm = 0;
    int d = 1;
    for(int i = 0 ; i<4 ;i++){
        cin >> arr[i];
        sm = sm + arr[i];
    }
    if(sm % 2 != 0){
        d = 0;
    }
    else{
        sm = sm/2;
    }
    sort(arr,arr+4);
    int t=arr[0];
    int i;
    for(i = 1 ; i<4 ; i++){
        if(t < sm){
          t = t + arr[i];
          if(t == sm){
              break;
          }
        }
        else{
           t = t - arr[i-1] ;
           break;
        }
        
    }
     if(t == sm && d == 1){
            cout<<"YES"<<endl;
    }
    else if(d == 0){
        cout<<"NO"<<endl;
    }
    else{
        if(arr[0] + arr[2] == sm || arr[0] + arr[3] == sm){
            cout<<"YES"<<endl;
        }
        
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}