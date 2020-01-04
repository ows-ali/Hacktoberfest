#include <bits/stdc++.h>
using namespace std;

int main() {
    long n,k,a,b;
    int t,count,l;
    cin>>t;
    while(t!=0)
    {
        count=0;
        cin>>n;
        cin>>a;
        cin>>b;
        cin>>k;
        count=(n/a)+(n/b);
        l=boost::math::lcm(a,b);
        l=n/l;
        count=count-(l*2);
        if(count>=k)
            cout<<"Win"<<endl;
        else
            cout<<"Lose"<<endl;
    t--;
    }
	return 0;
    
}