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

while(t--)
{
vector<pair<ll,ll> >v;
 ll i,j,sum=0,act=0,k,b,n,q,l,m;
 ll maxa=0,maxp=0;
cin>>n>>b;
for(i=0;i<n;i++)
    {
        cin>>j>>k>>l;

        v.push_back(make_pair(j*k,l));
        if(v[i].first>maxa && l<=b)
        {
            maxa=v[i].first;
            maxp=l;
        }
      
    }
    if(maxa!=0)
    {
    cout<<maxa<<endl;}
    else
    {
        cout<<"no tablet"<<endl;
    }
}
return 0;
}
