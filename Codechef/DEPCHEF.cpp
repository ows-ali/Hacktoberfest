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
vector<ll>a;
vector<ll>b;
 ll i,j,sum=0,act=0,k,n,q;
cin>>n;
a.reserve(n);
b.reserve(n);
for(i=0;i<n;i++)
    {
        cin>>j;
        a.push_back(j);
      
    }
    for(i=0;i<n;i++)
    {
        cin>>j;
        b.push_back(j);
      
    }
    ll max=0,save=-1;
 for(i=1;i<n;i++)
    {
        ll sum=a[i-1]+a[(i+1)%n];
        if(sum<b[i])
        {
            
            if(max<b[i])
            {
                save=i;
                max=b[i];
                
            }
        }
    }
        if(a[1]+a[n-1]<b[0])
        {
            if((b[0]>max) || max==0)
            {
                save=0;
            }
        }
      
        if(save==-1)
        {
            cout<<"-1"<<endl;
        }
        else{
        cout<<b[save]<<endl;}
       // cout<<"s"<<save<<endl;
}

return 0;
}


