# include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[100],x,beg,end,mid,i;
	cin>>n;
	for(i=0;i<n;++i)
	cin>>a[i];
	sort(a,a+n);
	cout<<"element to search\n";
	cin>>x;
	beg=0;
	end=n-1;
	while(a[mid]!=x && beg<=end)
	{
		mid=(beg+end)/2;
		if(a[mid]==x)
		cout<<"element found\n";
		else
		{
			if(a[mid]<x)
			beg=mid+1;
			else
			end=mid-1;
		}
	}
	if(beg>end)
	cout<<"element not found\n";
	return 0;
}
