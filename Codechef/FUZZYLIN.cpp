/*-------enazuma11----------------*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define inc(a,n) sort(a,a+n)
#define dec(a,n) sort(a,a+n,greater<int>() )
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--)
#define F first
#define S second
#define M 1000000007
 
/* int x[]={-1,-1,0,1,1,1,0,-1};
int y[]={0,1,1,1,0,-1,-1,-1};
*/
/* int x[]={-1,0,1,0};
int y[]={0,1,0,-1};
*/

const int N=1e6+3; 
ll a[100005];
map<ll,ll>ans;
ll val[N];
void solve()
{
	ll i,j,x,n,q;
	map<ll,ll>m1,m2;
	map<ll,ll>::iterator it;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	{
		for(it=m1.begin();it!=m1.end();it++)
		{
			m2[__gcd(it->first,a[i])]+=it->second;
			ans[__gcd(it->first,a[i])]+=it->second;
		}
		m2[a[i]]++;
		ans[a[i]]++;
		swap(m1,m2);
		m2.clear();
	}
	for(auto i:ans){
		//cout<<i.F<<" :";
		for(j=i.F;j<N;j+=i.F)
		{
			val[j]+=ans[i.F];
		}
		//cout<<'\n';
	}
	cin>>q;
	ll p;
	while(q--){
		cin>>p;
		cout<<val[p]<<'\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
//	cin>>t;
//	f();
	while(t--){
		solve();
	}
	return 0;
}
