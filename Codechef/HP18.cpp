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
 ll i,j,sum=0,act=0,k,n,q,a,b,countb=0,counta=0;
cin>>n>>a>>b;
for(i=0;i<n;i++)
    {
        cin>>j;
        if(j%a==0)
        {countb++;}
        else if(j%b==0)
        {
            counta++;
        }
        v.push_back(j);
      
    }
    if(countb>counta)
    {
        cout<<"BOB"<<endl;
    }
    else{
        cout<<"ALICE"<<endl;
    }
}
return 0;
}
