#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void makePermutation(int *arr,int i,int n,unordered_map<string,int> *freqmap){
	
	if(i == n){
	   string ans = "";
	   for(int j=0;j<n;j++){
	   	 ans += to_string(arr[j])+" ";
	   }
	   
	   if((*freqmap).find(ans) == (*freqmap).end()){
	   	(*freqmap)[ans] = 1;
	   }
	   else
		(*freqmap)[ans]++;
	   return;	
	}
	
	for(int j=0;j<n;j++){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		makePermutation(arr,i+1,n,freqmap);
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;

	string maxAns = "";
	for(int i=2;i<=(n+1)/2;i++){
	  maxAns += to_string(i)+" "; 
	}
	maxAns += "1 ";
	for(int i=2+(n+1)/2;i<=n;i++){
	  maxAns += to_string(i)+" "; 
	} 
	maxAns += to_string((n+3)/2)+" ";
	cout<<maxAns<<endl;
	string minAns = to_string(n)+" ";
	for(int i=1;i<n;i++){
	 minAns += to_string(i)+" ";	
	}
	cout<<minAns<<endl;
	return 0;
}