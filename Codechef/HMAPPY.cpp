#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define l long
int val, r_counter = -1;
void exclamation(vector<int> &d[2], int N)
{
	int temp;
	temp = d[N-1];
	if(r_counter >= N-1)
		r_counter = -1;
	d.pop_back();
	d.insert(d.begin(), temp);
}

void question(vector<int> &d[2], int N, int K)
{
	int count = 0, i, j, temp = 0;
	for(i = 0; i < N; i++)
	{
		if(d[i] == 1)
		{
			for(j = i;; j++)
			{
				if(d[j] == 0)
					break;
				temp++;
			}
			if(temp >= count)
			{
				r_counter = j;
				count = temp;
			}
			temp = 0;
			i = j;
		}
	}
	//cout<<"\nr_counter:"<<r_counter<<'\n';
	if(count > K)
		cout<<K<<' ';
	else cout<<count<<' ';
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, Q, K;
	int num;
	cin>>N>>Q>>K;
	vector<int> d[2];
	for(int i = 0; i < N; i++)
	{
		cin>>num;
		if(num == 0)
			d[0].push_back(num);
		else d[1].push_back(num);
	}
	val = num;
	char str[Q];
	cin>>str;
	for(int i = 0; i < Q; i++)
	{
		if(str[i] == '?')
			question(d, N, K);
		else exclamation(d, N);
	}
	return 0;
}