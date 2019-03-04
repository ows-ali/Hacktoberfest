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
    vector<ll>v;
while(t--)
{
   ll n;
    cin>>n;
    v.reserve(n);
    int arr[100000]={0};
    ll i,j,k,max=0;
    for(i=0;i<n;i++)
    {
        cin>>j;
        arr[j]++;
        if(j>max)
        {
            max=j;
        }
        v.push_back(j);
    }
    int flag=0;
    vector<pair<ll,ll>>m;
    m.reserve(n);
    //int freq[n+1]={0};
    for(i=0;i<n;i++)
    {
       m.push_back(make_pair(v[v[i]-1],v[i]));
       // freq[v[v[i]-1]]++;
    }
    sort(m.begin(),m.end());
                   for(i=1;i<m.size();i++)
                   {
                       if(m[i].first==m[i-1].first && m[i].second!=m[i-1].second)
                       {flag=1;
                       break;}

    
    
         
    }
         if(flag==1)
         {
             cout<<"Truly Happy"<<endl;
     }
         else
         {
            cout<<"Poor Chef"<<endl; 
         }
        
    v.clear();
   m.clear();
    
}
    
return 0;
}
