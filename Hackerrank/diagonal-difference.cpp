#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ar[n][n];
    int s1=0,s2=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ar[i][j];
            if(i==j){
                s1=s1+ar[i][j];
            }
            if ((i+j)==n-1) {
               s2=s2+ar[i][j];
            }
        }
    }
    
    cout<<abs(s2-s1)<<'\n';
    return 0;
}