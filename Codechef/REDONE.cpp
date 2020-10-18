// https://www.codechef.com/problems/REDONE
#include<iostream>
using namespace std;
long long mod=1e9+7;
int main(void)
{
    int t,n;
    long long arr[1000001];
    arr[1]=1;
    for(int i=2;i<=1e6;i++)
    {
        arr[i]=((i+arr[i-1])%mod+(i*arr[i-1])%mod)%mod;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<arr[n]<<endl;
    }
}
