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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    llin2(m,n);
    vll v(n);
    vecin(n,v);
    ll dp[m+1]={0};
    dp[0]=1;
    rep(i,1,n+1){
        rep(j,1,m+1){
            if(v[i-1]<=j)
                dp[j]+=dp[j-v[i-1]];
        }
    }
    cout<<dp[m];
    return 0;
}
