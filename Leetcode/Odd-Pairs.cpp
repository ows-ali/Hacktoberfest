#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	 cin>>t;
	 while(t--)
	 {
	     int n;
	     cin>>n;
	     int i=0;
	     int l=n;
         if(n==1)
         {
            cout<<0<<endl;
            continue;
         }
	     while(n)
	     {
	        i+=2;
	        n-=2;
	     }
	     cout<<i*2<<endl;
	 }  
	return 0;
}
