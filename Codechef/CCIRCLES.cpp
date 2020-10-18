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
#define MAX 1000005
#define lld long double
using namespace std;


bool isin(ll x1, ll y1, ll r, ll x2, ll y2){
    x1-=x2;
    y1-=y2;
    x1*=x1;
    y1*=y1;
    r*=r;
    return ((x1+y1) <= r);
}

int main()
{
    fast
	llin2(n,q);
	vector<tuple<ll, ll,ll> > v(n);
	rep(i,0,n){
	    llin3(x,y,r);
	    v[i]=make_tuple(x,y,r);
	}
	vector<ll> mn(MAX,0);
	rep(i,0,n){
	    rep(j,i+1,n){
	        if(get<0>(v[i])==get<0>(v[j]) && get<1>(v[i])==get<1>(v[j])){
	            mn[abs(get<2>(v[j]) - get<2>(v[i]))]++;
	            mn[abs(get<2>(v[j]) - get<2>(v[i]))+1]--;
	            continue;
	        }
	        lld d=(((lld)get<0>(v[ i])-get<0>(v[j])) * ((lld)get<0>(v[i])-get<0>(v[j]))) + (((lld)get<1>(v[i])-get<1>(v[j])) * ((lld)get<1>(v[i])-get<1>(v[j])));
	        d=sqrtl(d);
	        bool is;
	        if(get<2>(v[i]) > get<2>(v[j]))
	            is=isin(get<0>(v[i]), get<1>(v[i]), get<2>(v[i]), get<0>(v[j]), get<1>(v[j]));
	        else
	            is=isin(get<0>(v[j]), get<1>(v[j]), get<2>(v[j]), get<0>(v[i]), get<1>(v[i]));
	        if(is){
    	        lld s= abs(get<2>(v[j]) - get<2>(v[i])) - d;
    	        lld e=d + (get<2>(v[i]) + get<2>(v[j]));
    	        mn[max((ll)ceil(s), (ll)0)]++;
    	        mn[min((ll)floor(e), (ll)MAX-2)+1]--;
	        }
	        else{
	            lld s=d-(get<2>(v[i]) + get<2>(v[j]));
    	        lld e=d+(get<2>(v[i]) + get<2>(v[j]));
    	        mn[max((ll)ceil(s), (ll)0)]++;
    	        mn[min((ll)floor(e), (ll)MAX-2)+1]--;
	        }
	    }
	}
	rep(i,1,MAX)
	    mn[i]+=mn[i-1];
	while(q--){
	    llin(k);
	    cout<<mn[k]<<endl;
	}
    return 0;
}
