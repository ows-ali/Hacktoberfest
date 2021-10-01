#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void candies(long int a[],long int n){
    
    long int l[n],r[n];
    l[0]=1;
    for(long int i=1;i<n;i++){
        if(a[i]<=a[i-1]){
            l[i]=1;
        }
        else
        {
            l[i]=l[i-1]+1;
        }
    }
    
    r[n-1]=1;
    for(long int i=n-2;i>=0;i--){
        if(a[i]<=a[i+1]){
            r[i]=1;
        }
        else
        {
            r[i]=r[i+1]+1;
        }
    }
    
    long int sum=0;
    for(long int i=0;i<n;i++){
        sum+=max(r[i],l[i]);
    }
    cout<<sum<<endl;
}

int main(){
    long int n;
    cin>>n;
    long int a[n];
    for(long int i=0;i<n;i++){
        cin>>a[i];
    }
      
    candies(a,n);
    
    return 0;
}
