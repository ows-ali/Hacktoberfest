#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t!=0)
	{
		t--;
		long long int n,q,a,b,prev=0;
		cin>>n>>q;
		long long int initial=0;
		long long int sum=0;
		for(int i=0;i<q;i++)
		{
			cin>>a>>b;
			sum=sum+abs(prev-a)+abs(b-a);
			prev=b;
		}
		cout<<sum<<endl;	
	}
	return 0;
}	
