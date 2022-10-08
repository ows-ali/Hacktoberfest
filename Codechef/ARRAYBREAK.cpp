#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// const int N = 1e5+10;
// int arr[N];

int main() {
	int t,n,count,ele,oddn;
	cin>>t;
	while(t--){
	    count=0;
	    oddn=0;
	    cin>>n;
	    int * arr=(int *)malloc(n*sizeof(int));
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        ele=arr[i];
	        if(ele%2==0)
	            count++;
	        else
	            oddn++;
	    }
	    if(oddn!=0)
	    cout<<count<<endl;
	    else
	        cout<<0<<endl;
	}
	return 0;
}
