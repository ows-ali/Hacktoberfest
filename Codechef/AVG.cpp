#include<bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define MAXN 500003
typedef long long ll;
using namespace std;




int main(){
    
    
        ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t;
cin>>t;

while(t--)
{
vector<ll>v;
 ll sum=0,act=0,k,n,q,f,a;
cin>>n>>k>>a;
v.reserve(n);
forr(i,0,n)
    {
        cin>>f;
        v.pb(f);
      sum+=f;
    }
    ll x=(a)*(n+k) -sum;
    
    if(x>0 && x%k==0)
    {
        cout<<x/k<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
}
return 0;
}

