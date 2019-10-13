#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, i, j, k, N;
	long flag, temp = 0 , temp1 = 1;
	cin>>t;
	while(t--)
	{
		cin>>N;
		if(N == 1)
			cout<<"1 2 ";
		else if(N == 2)
			cout<<"1 4 ";
		else
		{
			long long sum = 1;
			for(i = 3; i <= N; i++)
			{
				if(i%2 == 0)
					sum = 2*sum - 1;
				else
					sum = 2*sum + 1;
			}
			cout<<sum<<' ';
			sum = 2;
			for(i = 0; i < N-1; i++)
			{
				sum = sum * 2;
			}
			cout<<sum<<' ';
		}
	}
	return 0;
}