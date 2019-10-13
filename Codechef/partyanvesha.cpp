/* ~created by Pratik~ */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,p,n,c=0;
		cin>>n;
		p=n;
		while(n>0)
		{
			n/=2;
			c++;
		}
		if((p&(p-1))==0) c--;
		cout<<c<<endl;
	}
	return 0;
}
