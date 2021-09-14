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
vector<ll>v;
 ll i,j,sum=0,act=0,k,n,q;
cin>>n;
v.reserve(n);
for(i=0;i<n;i++)
    {
        cin>>j;
        v.push_back(j);
        sum+=j-1;
      
    }
    cout<<sum+1<<endl;
}
return 0;
}
