/* ~created by Pratik~ */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	long long int p[n],q[m],a[200010]={0} ,max=0;
	for(i=0;i<n;i++)
	{
		cin>>p[i];
	}
	for(i=0;i<m;i++)
	{
		cin>>q[i];
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j>=i && (n-j)>=(m-i))
			{
				a[j-i]+=(p[j]*q[i]);
//////////////////				cout<<a[j-i]<<" "<<p[j]<<" "<<q[i]<<endl;
				if(a[j-i]>max) max=a[j-i];
			}
		}
	}
	cout<<max<<endl;
	return 0;
}
