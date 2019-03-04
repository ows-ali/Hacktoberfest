#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
int main()
{
ll t;
cin>>t;
while(t--)
{
ll a,b,n,k;
cin>>n>>a>>b>>k;
ll count1=0,count2=0,count3=0;
count1=floor(n/a);
count2=floor(n/b);
ll temp=(a*b)/__gcd(a,b);
count3=floor(n/temp);
if((count1+count2-(2*count3)>=k))
{cout<<"Win"<<endl;}
else
{
cout<<"Lose"<<endl;
}

}
return 0;
}

