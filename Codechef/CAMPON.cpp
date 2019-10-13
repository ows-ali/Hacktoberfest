/* ~created by Pratik~ */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,d,p,a[32]={0},j;
		for(i=0;i<n;i++)
		{
			cin>>d>>p;
			for(j=d;j<=31;j++)
			{
				a[j]+=p;
			}
		}
		int q,da,re;
		cin>>q;
		for(i=0;i<q;i++)
		{
			cin>>da>>re;
			if(a[da]<re) cout<<"Go Sleep\n";
			else cout<<"Go Camp\n";
		}
	}
	return 0;
}
