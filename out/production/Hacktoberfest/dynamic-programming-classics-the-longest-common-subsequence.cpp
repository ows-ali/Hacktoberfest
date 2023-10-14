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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

        llin2(n,m);
        vll v(n);
        vecin(n,v);
        vll w(m);
        vecin(m,w);
        ll dp[n+1][m+1];
        rep(i,0,m+1)
            dp[0][i]=0;
        rep(i,0,n+1)
            dp[i][0]=0;
        rep(i,1,n+1)
        {
            rep(j,1,m+1)
            {
                if(v[i-1]==w[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else    
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string s="";
        for(ll i=n, j=m; i>0&&j>0;){
            if(v[i-1]==w[j-1]){
                s=to_string(v[i-1])+" "+s;
                i--;
                j--;
            }
            else if(dp[i][j-1]>dp[i-1][j])
                j--;
            else
                i--;
        }
        cout<<s;
    
    return 0;
}
