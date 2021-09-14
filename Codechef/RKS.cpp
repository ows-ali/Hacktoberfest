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
 ll r,c;
 q=0;
cin>>n>>k;
ll row[n]={0},col[n]={0};
vector<pair<ll,ll>>v;
v.reserve(n);
for(i=0;i<k;i++)
    {
        cin>>r>>c;
        row[r-1]=1;
        col[c-1]=1;
        v.push_back(make_pair(r,c));
      
    }
    if(n==1)
    {
        if(k==1)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<"1 1 1"<<endl;
        }
        continue;
    }
 vector<ll>emp;
 vector<pair<ll,ll>>res;
 res.reserve(n);
 emp.reserve(n);   
 for(i=0;i<n;i++)
 {
     if(col[i]==0)
     {
         emp.push_back(i+1);
     }
}
sort(emp.begin(),emp.end());
j=0;
for(i=0;i<n;i++)
{
    if(row[i]==0)
    {
res.push_back(make_pair(i+1,emp[j]));
j++;
    }
}
ll len=res.size();
cout<<len<<" ";
for(i=0;i<len;i++)
{
    cout<<res[i].first<<" "<<res[i].second<<" ";
}
cout<<endl;
 
}
return 0;
}
