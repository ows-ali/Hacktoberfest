#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	ll t;
	cin>>t;
	while(t--){
	    ll n,s;
	    cin>>n>>s;
	    if(n==s){
	        cout<<n<<endl;
	    }
	    if(n>s){
	        cout<<s<<endl;
	    }
	    if(s>n){
	        int sum=n;
	        int d=s-sum;
	        cout<<sum-d<<endl;
	    }
	}
	return 0;
}
