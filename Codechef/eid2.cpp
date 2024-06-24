/* ~created by Pratik~ */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a1,a2,a3,c1,c2,c3,f=0;
		cin>>a1>>a2>>a3>>c1>>c2>>c3;
		vector< pair<int, int> > v;
		v.push_back( make_pair(a1,c1) );
		v.push_back( make_pair(a2,c2) );
		v.push_back( make_pair(a3,c3) );
		sort(v.begin(),v.end());
		c1=v[0].second;
		c2=v[1].second;
		c3=v[2].second;
		if(v[0].first == v[1].first)
		{
			if(c1!=c2) {f=1;cout<<"NOT FAIR\n";continue;}
			if(v[1].first == v[2].first)
				if(c2!=c3) 
					{f=1;cout<<"NOT FAIR\n";continue;}
			if(v[1].first < v[2].first)
				if(!(c2<c3)) 
					{f=1;cout<<"NOT FAIR\n";continue;}
			
		}
		else if(v[0].first < v[1].first)
		{
			if(!(c1<c2)) {f=1;cout<<"NOT FAIR\n";continue;}
			if(v[1].first == v[2].first)
				if(c2!=c3) 
					{f=1;cout<<"NOT FAIR\n";continue;}
			if(v[1].first < v[2].first)
				if(!(c2<c3)) 
					{f=1;cout<<"NOT FAIR\n";continue;}
		}
		if(f==0)
			cout<<"FAIR\n";
		
	}


	return 0;
}
