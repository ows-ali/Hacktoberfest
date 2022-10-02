#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,tmp,flag=0;
    cin>>n;
    int i;
    for(i=0;i<n;i++){
        cin>>tmp;
        if(tmp)
            flag=1;
    }
    if(flag)
        cout<<"HARD";
    else
        cout<<"EASY";
    return 0;
}