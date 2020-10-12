#include <bits/stdc++.h>
using namespace std;



int main() 
{
	int n,t;
	cin>>t;	
	for(long long int i=0;i<t;i++)
	{
	 	int s,a1,a2,a3;
		cin>>s>>a1>>a2>>a3;
		
		int c=0;
		if((a1+a2)<=s)
		{
			if((a1+a2+a3)<=s)
			{
				c++;
			}
			else
			{
				c=c+2;	
			}
		}
		else if(a1<=s && (a1+a2)>s)
		{
			c++;
			if(s==1)
			{
				if(a2==1 && a3==1)
				{
					c=c+2;
				}
				else if((a2==2 && a3==1) || (a2==1 && a3==2))
				{
					c=c+3;
				}
				
			}
			else
			{
				if((a2+a3)<=s)
				{
					c=c+1;
				}
				else
				{
					c=c+2;
				}
			}
		}
		else
		{
			c=c+2;
		}
		cout<<c<<endl;
	}
	return 0;
} 
