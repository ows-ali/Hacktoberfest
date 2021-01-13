#include<bits/stdc++.h>
using namespace std;

 
long long int t, n, k;

int main(){
	
	float ans;
    cin>>t;
    while(t--){
    	cin>>n>>k;

    	ans = 2 + (2*(n-1)*(k-1))/(k*1.0);
    	cout<< fixed << setprecision(7) <<ans<<endl;
    }
 
    return 0;
}
