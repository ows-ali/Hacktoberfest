/* ~created by Pratik~ */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,e,s,i;
		cin>>n>>e>>s;
		long long int j,a[n],k,max=-1,sum;
		long double val,mavg=-1;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=s;i<=e;i++)
		{
			sum=0;
			for(k=0;k<s;k++)
				sum+=a[k];
			if(sum>max) max=sum;
			for(j=s;j<=(n-1);j++)
			{
				sum+=(a[j]-a[j-s]);
				if(sum>max) max=sum;
			}
			val = (long double)max/i;
			if(val>mavg) mavg = val;
		}
		cout<<fixed<<setprecision(7)<<mavg<<endl;
				
	}
	return 0;
}
