/* ~created by Pratik~ */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,t;
	string s;
	cin>>t;
	cin>>s;
	char a[27];
	for(i=0;i<26;i++)
	{
		a[i]=s[i];
	}
	while(t--)
	{
		string p;
		cin>>p;
		int l=p.length(),d;
		char c;
	//	cout<<l;
		for(i=0;i<l;i++)
		{
			if(p[i]>='a'&&p[i]<='z')
			{
				c=a[(int)p[i]-'a'];
				p[i]=c;
			}
			else if(p[i]>='A'&&p[i]<='Z')
			{
				c=a[(int)p[i]-'A']-32;
				p[i]=c;
			}
			else if(p[i]=='_')
				p[i]=' ';
		}
		cout<<p<<endl;
	}



	return 0;
}
