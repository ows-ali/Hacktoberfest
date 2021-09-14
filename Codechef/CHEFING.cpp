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
vector<string>v;
vector<array<ll,26>>p;
 ll i,j,sum=0,act=0,k,n,q,a,b;
cin>>n;
v.reserve(n);
p.reserve(n);
for(i=0;i<n;i++)
    {
        string f;

        cin>>f;
        v.push_back(f);
        array<ll,26> arr{0};
        for(j=0;j<f.length();j++)
        {
arr[f[j]-'a']++;
//cout<<f[j]<<arr[f[j]-'a']<<endl;
        }
       // p[i].reserve(26);
        p.push_back(arr);
      
    }
    ll count=0;
    for(i=0;i<26;i++)
    {
       bool flag=true;
        for(j=0;j<n;j++)
        {
            
if(p[j][i]==0)
{
flag=false;
break;
}
        }
        if(flag)
        {
            count++;
        }
    }
    cout<<count<<endl;
}
return 0;
}
