#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<2*n;i+=2)
        cout<<i<<" ";
        cout<<"\n";
    }
	return 0;
}