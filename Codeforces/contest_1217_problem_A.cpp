// problem url https://codeforces.com/contest/1217/problem/B
#include<iostream>
using namespace std;
typedef unsigned int ui;

int main(){
    int t;
    cin>>t;
    int r[t];
    int n;
    int x[t],dm[t];
    int dx[t];
    for(int i=0;i<t;i++){
        dm[i] = 0;
        dx[i] = -999999999;
        cin>>n>>x[i];
        for(int j=0;j<n;j++){
            int d,h;
            cin>>d>>h;
            if(d>dm[i]){
                dm[i] = d;
            }
            if((d-h)>dx[i]){
                dx[i] = d-h;
            }
        }
    }
    for(int i=0;i<t;i++){
        if(dm[i]>=x[i]){
            r[i]=1;
        }
        else if(dx[i]<=0){
            r[i]=-1;
        }
        else{
            x[i]-=dm[i];
            int k = x[i]/dx[i];
            if(x[i]%dx[i] == 0){
                r[i] = k+1;
            }
            else{
                r[i] = k+2;
            }
        }
    }
    for(int i=0;i<t;i++){
        cout<<r[i]<<"\n";
    }
    return 0;
}