#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
const int mod = 1000000007;
int main()
{
   ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t;
cin>>t;

while(t--)
{
    
 ll i,j,sum=0,act=0,k,n,q;
cin>>n;
string a;
cin>>a;
if(n==1)
{
    if(a[0]=='1')
    {
        cout<<"0"<<endl;
    }
    else
    {
        cout<<"1"<<endl;
    }
    continue;
}
ll count=0;
if(a[0]=='0' && a[1]=='0')
{
    a[0]='1';
    count++;
}
for(i=1;i<n-1;i++)
{
if(a[i]=='0' && a[i-1]=='0' && a[i+1]=='0')
{
    a[i]='1';
    count++;
    //cout<<"i"<<i<<endl;
}
}
if(a[n-2]=='0' && a[n-1]=='0')
{a[n-1]='1';
count++;

}
cout<<count<<endl;
}
return 0;
}
