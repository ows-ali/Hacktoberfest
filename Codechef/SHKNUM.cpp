// https://www.codechef.com/AUG18B/problems/SHKNUM


#include <bits/stdc++.h>
using namespace std;

typedef		long long int 	ll;
#define		rep(i,n) 		for(i=0;i<n;i++)
#define		repe(i,I1,I2) 	for(i=I1;i<I2;i++)
#define		INF  			1e9 + 7


ll setbit(ll n)
{
    if (n == 0)
        return 0;
    ll msb = 0;
    while (n != 0)
    {
        n = n / 2;
        msb++;
    }
    return (msb);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,i,x,ans,y,a,b,p,q,sm,lr;
	cin>>t;
	while(t--)
	{
		cin>>x;
		if(x==0 || x==1)
		{
			ans=3-x;
			cout<<ans;
			if(t!=0)
				cout<<"\n";
			continue;
		}
		a=setbit(x);
		p=1<<(a-1);
		//cout<<"\n!@a "<<a<<" # "<<p;
		y=x-p;
		b=setbit(y);
		if(b==0)
		{
			ans=1;
			cout<<ans;
			if(t!=0)
				cout<<"\n";
			continue;
		}
		q=1<<(b-1);
		sm=p+q;
		if(a==(b+1))
			lr= (pow(2,a))+1;
		else
			lr=p+(q*2);
		ans= min(x-sm,lr-x);
		cout<<ans;
		if(t!=0)
			cout<<"\n";
	}
	return 0;
}