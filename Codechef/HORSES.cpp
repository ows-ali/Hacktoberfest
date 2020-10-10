#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		int S[n];
		for(int j=0;j<n;j++)
		{
			cin>>S[j];
		}
		
		n=sizeof(S)/sizeof(S[0]);
		sort(S,S+n);
		
		
		vector<int> v;
		int* li;
		for(int k=1;k<n;k++)
		{
			int a=S[k]-S[k-1];
			v.push_back(a);
		}
		cout<<*min_element(v.begin(),v.end())<<endl;
		
	}
}
