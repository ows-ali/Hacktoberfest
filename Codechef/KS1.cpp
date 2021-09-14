// https://www.codechef.com/AUG19B/problems/KS1
// Vivek Rai blazer_007

#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define FF           first
#define SS           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define loop(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

void solution(){
	ll n,x;
	cin>>n;
	vi v,xorr;
	cin>>x;
	v.pb(x);
	xorr.pb(x);
	loop(i,1,n){
		cin>>x;
		v.pb(x);
		xorr.pb(x^xorr[i-1]);
	}
	ll ans=0;
		map<long,vector<long> > mp;
        mp[0].push_back(0);
        loop(i,0,n)
            mp[xorr[i]].push_back(i+1);
        for(auto it=mp.begin();it!=mp.end();it++)
        {       for(int i=(it->second.size()-1);i>=0;i--)
                    ans+=it->second[i]*i-(it->second.size()-i-1)*it->second[i];
                    ans-=((it->second.size())*(it->second.size()-1))/2;
        }
        cout<<ans<<endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1 ;
    
    cin>>t;
    while(t--){
    	solution();
	}
    
    return 0;
}
