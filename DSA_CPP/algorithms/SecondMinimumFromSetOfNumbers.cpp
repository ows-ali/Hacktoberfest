#include <bits/stdc++.h>
using namespace std;

void secondMin(const vector <int> v)
{
	int sMin=INT_MAX;
	int min=v[0];
	for(int i=0;i<v.size();++i)
	{
		if(min>v[i])
		{
			min=v[i];
		}
	}
	for(int i=0;i<v.size();++i)
	{
		if(v[i]<sMin && v[i]>min)
		{
			sMin=v[i];
		}
	}
	cout<<sMin;

}

int main()
{
	vector <int> v;
	int n;
	cout<<"Enter the number of elements to be entered: ";
	cin>>n;
	int x;
	while(n--)
	{
		cin>>x;
		v.push_back(x);
	}
	secondMin(v);

	return 0;
}