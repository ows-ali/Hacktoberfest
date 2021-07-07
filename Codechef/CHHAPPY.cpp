#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define l long

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, i, j, k, N, temp, temp1, flag;
	cin>>t;
	while(t--)
	{
		cin>>N;
		vector<int> A[N+1];
		for(i = 1; i <= N; i++)
		{
			cin>>temp;
			A[temp].push_back(i);
		}
		flag = 0;
		for(i = 1; i <= N; i++)
		{
			temp = 0;
			j = 0;
			if(A[i].size() > 1)
			{
				for(k = 0; k < A[i].size(); k++)
				{
					temp1 = A[i][j++];
					if(A[temp1].size() >= 1)
						temp++;
				}
			}
			if(temp >= 2)
			{
				cout<<"Truly Happy\n";
				flag++;
				break;
			}
		}
		if(flag == 0)
			cout<<"Poor Chef\n";
	}
	return 0;
}