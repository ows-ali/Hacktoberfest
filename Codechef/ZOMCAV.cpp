#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int c[n+1],h[n+1],ans[n+1],H[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>c[i];
			h[i]=0;
		}
		for(int i=1;i<=n;i++)
			cin>>H[i];
		for(int i=1;i<=n;i++)
		{
			int l,hi;
			l=max(1,i-c[i]);
			h[l]++;
			hi=i+c[i]+1;
			if(hi<=n)
			{
				h[hi]--;
			}
		}
		ans[0]=0;
		for(int i=1;i<=n;i++)
		{
			ans[i]=ans[i-1]+h[i];
		}
		sort(H+1,H+n+1);
		sort(ans+1,ans+n+1);
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(ans[i]!=H[i])
			{
				flag=0;
				break;
			}
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
