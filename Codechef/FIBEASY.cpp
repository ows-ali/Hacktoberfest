//https://www.codechef.com/SEPT19B/problems/FIBEASY
#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
	cin>>t;
	for(long double i=0;i<t;i++){
	    long double n;
	    cin>>n;
	    if(n==0){cout<<"0\n";continue;}
	    if(n==1){cout<<"0\n";continue;}
	    if(n==2){cout<<"1\n";continue;}
	    if(n==3){cout<<"1\n";continue;}
	    long long p=(long long)log2(n);
	    if(p%4==0){cout<<"0\n";continue;}
	    if(p%4==1){cout<<"9\n";continue;}
	    if(p%4==2){cout<<"2\n";continue;}
	    if(p%4==3){cout<<"3\n";continue;}
	    
	    
	}
    return 0;
}
