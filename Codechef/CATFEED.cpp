//Codechef Lunchtime September 2019
//Problem Link https://www.codechef.com/problems/CATFEED
//By Satyam (https://www.codechef.com/users/sat_yam_) 


#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>n>>m;
        int a[m];
        for (int i = 0; i < m; i++) {
            cin>>a[i];
        }
        int s[n],c=0,temp;
        for (int j = 0; j < n; j++) {
            s[j]=0;
        }
        for (int i = 0; i < m; i++) {
            temp = a[i]-1;
            s[temp] = 1;
            int sum=0;
            if((i+1)%n==0 && i!=0){
                for (int j = 0; j < n; j++) {
                    sum+=s[j];
                    s[j]=0;
                }
                if(sum!=n){
                    c=1;
                    break;
                }
            }
        }
        if(!c){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}