/* ~created by Pratik~ */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,k,f=0;
		cin>>n;
		vector<int> a;
		for(i=0;i<n;i++)
		{
			cin>>k;
			a.push_back(k);
		}
		sort(a.begin(),a.end());
		for(i=0;i<n-1;i++)
		{
	//		cout<<a[i]<<" ";
			if(a[i]==a[i+1]) 
			{
				f=1;
				break;
			}
		}
	//	cout<<endl;
		if(f) cout<<"yes\n";
		else cout<<"no\n";
	}


	return 0;
}
