#include<bits/stdc++.h>
using namespace std;

bool isPowerOf2(int n)
{
	if(n && (n & (n-1))==0)       
	return true;
	else                             
	return false;
}

int main()
{
	int n; cin>>n;
	
	if(isPowerOf2(n))
	cout<<"Yes\n";
	else
	cout<<"No\n";
	
	return 0;
}
