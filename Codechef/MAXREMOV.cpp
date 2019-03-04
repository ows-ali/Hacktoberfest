#include<bits/stdc++.h>
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
ll mult(ll a,ll b, ll p=MOD){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD){return (a%p + b%p)%p;}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n%p; n = n * n%p;} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}
ll inv_euclid(ll a, ll m = MOD){ll m0 = m;ll y = 0, x = 1;if (m == 1)return 0;while (a > 1){ll q = a / m;ll t = m;m = a % m, a = t;t = y;y = x - q * y;x = t;}if (x < 0)x += m0;return x;}



int main(){
    
    
        ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t;
cin>>t;

while(t--)
{
vector<ll>vk;
vector<ll>vg;
vector<pair<ll,ll> >v;

 ll sum=0,act=0,k,n,q,f,l;
cin>>n>>k;
v.reserve(n);
ll ht[1000001]={0};
forr(i,0,n)
    {
        cin>>f>>l;
        v.pb(mp(f,l));
        ht[f]++;
        ht[l+1]--;
      
    }
    forr(i,1,1000001)
    {
        ht[i]=ht[i]+ht[i-1];
    }
    forr(i,1,1000001)
    {
        if(ht[i]==k)
        {
            vk.pb(i);
        }
        if(ht[i]==k+1)
        {
            vg.pb(i);
        }
    }
    ll x=vk.size();
    ll max=0;
    forr(i,0,n)
    {
auto low=lower_bound(all(vk),v[i].first);
auto high=upper_bound(all(vk),v[i].second);
ll y=high-low;
auto low1=lower_bound(all(vg),v[i].first);
auto high1=upper_bound(all(vg),v[i].second);
ll z=high1-low1;
ll temp=x-y+z;
if(max<temp)
{
    max=temp;
}
    }
    cout<<max<<endl;

}
return 0;
}

