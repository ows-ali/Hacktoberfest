#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a=0,b=0,c;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>arr[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<i+1;j++)
        a+=arr[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=n-i-1;j>n-i-2;j--)
        b+=arr[i][j];
    }
    c=abs(a-b);
     cout<<c;
}
