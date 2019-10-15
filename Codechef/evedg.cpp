#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int t,n,m,x,y,k,f;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int a[n];
		int arr[100001]={0};
		for(int i=0;i<m;i++){
			cin>>x>>y;
			arr[x-1]++;
			arr[y-1]++;
		}
		if(m%2==0){
			cout<<1<<endl;
			for(int j=0;j<n;j++)
				cout<<1<<" ";
			
		}
		else{
			k=0;
			for(int i=0;i<n;i++){
				if(arr[i]%2!=0){
					f=i;
					k=1;
					break;
				}
			}
			if(k==0){
				cout<<3<<endl;
				for(int j=0;j<n;j++){
					if(j==x-1)
						cout<<2<<" ";
					else if(j==y-1)
						cout<<3<<" ";
					else cout<<1<<" ";
				}
			}
			else{
				cout<<2<<endl;
				for(int j=0;j<n;j++){
					if(j==f)
						cout<<2<<" ";
					else cout<<1<<" ";
				}
			}

		}
		cout<<endl;
	}
	return 0;
}