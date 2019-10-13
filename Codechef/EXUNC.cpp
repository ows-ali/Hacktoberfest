/*
    * @authr AVINISH KUMAR
    * @college BIT MESRA
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define maxn 100000000000017
#define endl "\n"
typedef long long ll;
typedef double db;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin>>n>>q;
    ll inf = 100000000000;
    ll par[n+5];
    ll a[n+5];
    map<ll,ll> m;
    for(ll i=1;i<=n;i++)
    {   
        ll x;
        cin>>x;
        a[i]=x;
        // o1(x)
        if(i==1 || a[i]%a[i-1]!=0)
        {
            m[i]=1;
            par[i]=i;
        }
        else
        {
            par[i]=inf;
        }
    }

    while(q--)
    {
        ll f;
        cin>>f;
        if(f==1)
        {
            ll x,y;
            cin>>x>>y;
            par[x+1]=x+1;
            a[x]=y;
            if(x>1 && y%a[x-1]==0)
            {
                par[x]=inf;
                m.erase(x);
            }
            else
            {
                m[x]=1;
            }
            if(x<n && a[x+1]%y==0)
            {
                par[x+1]=inf;
                m.erase(x+1);
            }
            else
            {
                m[x+1]=1;
            }
            
        }
        else
        {
            ll x;
            cin>>x;
            auto it = m.upper_bound(x);
            it--;
            cout<<it->first<<endl;
        }
        
    }

}
