#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
#define mkp make_pair
#define endl "\n"
#define test cout<<"test line"<<endl;
#define swapper void swap(ll *a, ll *b){ll t=*a;*a=*b;*b=t;}
#define pll pair<ll,ll>
#define vpll vector<pll >
#define mod 1000000007
#define INF 0x3f3f3f3f
using namespace std;



int main()
{
    fast
    
    llin(t);
    while(t--)
    {
        llin(n);
        vll v;
        cin.ignore();
        string s;
        getline(cin,s);
        stringstream str(s);
        ll x;n=0;
        while(str>>x){
            v.pb(x);
            n++;
        }
        ll mx=0;x=0;
        rrep(i,n-1,0){
            mx=max(v[i],mx);
            x+=mx-v[i];
            //cout<<v[i]<<" ";
        }
        cout<<x<<endl;
    }
    return 0;
}
