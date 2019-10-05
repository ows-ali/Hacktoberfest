#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll a[n], b[n]={0};
	    for(ll i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    for(ll i=0;i<n;i++){
	        ll f = 0;
	        for(ll j=0;j<n;j++){
	            if(a[i] < a[j]){
	                f++;
	            }
	        }
	        b[i] = f;
	    }
	    
	    
	    for(ll i=0;i<n;i++){
	       cout<<b[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
