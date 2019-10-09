#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int sal;
	    float hra,da;
	    cin>>sal;
	    if( sal < 1500){
	        hra = sal*0.1;
	        da = sal*0.9;
	    }else{
	        hra = 500;
	        da = sal*0.98;
	    }
	    cout<<fixed<<setprecision(2)<<sal+hra+da<<endl;
	}
	return 0;
}
