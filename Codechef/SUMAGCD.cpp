#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll gcd(ll a,ll b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
}
ll f(ll num, ll arr[],ll n){
	ll res,i=0;
	while(arr[i]==num){
		i++;
	}
	if(i==n){
		return 2*num;
	}
	res=arr[i];
	for(i=0;i<n;i++){
		if(arr[i]!=num){
			res=gcd(res,arr[i]);
		}
	}
	return (res+num);
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		ll n,i;
		cin>>n;
		ll arr[n];
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		ll fir,sec=-1;
		fir=arr[max_element(arr,arr+n)-arr];
		for(i=0;i<n;i++){
			if((arr[i]>=sec)&&(arr[i]!=fir)){
				sec=arr[i];
			//	cout<<".."<<sec;
			}
		}
		//cout<<sec<<" "<<fir<<" ";
	//	cout<<f(sec,arr,n);
		cout<<max(f(fir,arr,n),f(sec,arr,n))<<endl;
	}
	return 0;
}
