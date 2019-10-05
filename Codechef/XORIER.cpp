#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


long nC2(long temp)
{
	if(temp<2)
	{
		return 0;
	}
	long temp2;
	if(0!=temp%2)
	{
		temp2 = (temp-1)/2;
	}
	else
	{
		temp2 = (temp)/2;
		temp = temp-1;
	}
	return temp*temp2;
}


int main()
{
	int test, N, i, j, evn, odd;
	long ans, neg;
	cin >> test;
	while(test--)
	{
		evn = 0;
		odd = 0;
		neg = 0;
		cin >> N;	
		unordered_map<int,int> cnt;
		unordered_map<int,int> :: iterator it;
		for(i = 0; i < N; i++)
		{
			cin >> ans;
			it=cnt.find(ans);
			if(cnt.end()!=it)
			{
				++(it->second);
			}
			else
			{
				cnt.insert({{ans,1}});
			}
			if(0==ans%2)
			{
				++evn;
			}
			else
			{
				++odd;
			}
		}
		int temp = 0, temp2;
		for(unordered_map<int,int> :: iterator it1 = cnt.begin(); it1!=cnt.end(); )
		{

			temp = it1->second;
			neg += nC2(temp);
//			cout << neg << endl;
			temp2 = (it1->first) +2;
			it=cnt.find(temp2);
			if(it!=cnt.end())
			{
				if(2 == (temp2^(it1->first)))
				{
//					cout << "+2   " << temp2 << "   " << it1->first << "    " << (temp2^(it1->first)) << endl;
					neg+=temp*it->second; 
				}
			}
			temp2=(it1->first)-2;
			it=cnt.find(temp2);
			if(it!= cnt.end())
			{
				if(2 == (temp2^(it1->first)))
				{
//					cout << "-2   " << temp2 << "   " << it1->first << "    " << (temp2^(it1->first)) << endl;
					neg+=temp*it->second;
				}
			}
			it=it1;
			++it1;
			cnt.erase(it);
		}

		ans = nC2(evn) +nC2(odd)-neg;
		cout << ans << endl;
//		cout <<evn << "   " << nC2(evn) << "   " <<odd << "   " << nC2(odd) << "   " << neg << "   "  <<ans << endl;
	}
	return 0;
}

