#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define llin(a) ll a; cin>>a; 
#define llin2(a,b) ll a,b; cin>>a>>b; 
#define llin3(a,b,c) ll a,b,c; cin>>a>>b>>c; 
#define fulll(v) v.begin(),v.end()
#define vecin(n, v) for(ll i=0; i<n;i++) cin>>v[i];
#define vecout(n, v) for(ll i=0; i<n;i++) cout<<v[i]<<" "; cout<<endl;
#define rep(i, s, n) for(ll i=s;i<n;i++)
#define rrep(i, s, n) for(ll i=s;i>=n;i--)
#define pb push_back
#define mp make_pair
#define endl "\n"
#define test cout<<"test line"<<endl;
#define swapper void swap(ll *a, ll *b){ll t=*a;*a=*b;*b=t;}
#define pll pair<ll,ll>
#define vpll vector<pll >
#define mod 1000000007
#define INF 0x3f3f3f3f
using namespace std;

int bs(vll &v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }
 
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    llin(n);
    vll v(n),w(n,0);
    vecin(n,v)
    w[0]=v[0];
    ll c=1;
    rep(i,1,n)
    {
        if(v[i]<w[i])
            w[0]=v[i];
        else if(v[i]>w[c-1])
            w[c++]=v[i];
        else
            w[bs(w,-1,c-1,v[i])]=v[i];
    }
    cout<<c;
    return 0;
}
