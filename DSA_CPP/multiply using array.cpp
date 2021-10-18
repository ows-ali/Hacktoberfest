#include<iostream>
using namespace std;
int digit(int n)
{
	int m=0;
	while(n!=0)
	{
		n=n/10;
		m++;
	}
	return m;
}

int main()
{
	int a,b;
	cin>>a>>b;
	int m=digit(a);
	int ar[m];
	for(int i=0;i<m;i++)
	{
		ar[i]=a%10;
		a=a/10;
	}
	int temp=0;
	for(int i=0;i<m;i++)
	{
		int x=ar[i]*b + temp;
		ar[i]=x%10;
		temp=x/10;
	}
	
	while(temp!=0)
	{
		ar[m]=temp%10;
		temp=temp/10;
		m++;
	}
	for(int j=m-1;j>=0;j--)
	{
		cout<<ar[j];
	}
	return 0;
}
