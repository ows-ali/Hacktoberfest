#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
const int mod = 1000000007;
int main()
{
   ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t;
cin>>t;
    ll x=t;
    vector<ll>v;
    ll nu,de;
while(t--)
{
    
    v.reserve(2*t);
    ll n,num=1,den=2;
    cin>>n;
    if(n==1)
    {
    v.push_back(1);}
    else
    {
       for(ll i=2;i<=n;i++)
       {
           num=den-num;
           den=(ll)pow(2,i);
       }
        v.push_back(num);
    }
    v.push_back((ll)pow(2,n));
}
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
return 0;
}
