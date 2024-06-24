#include <bits/stdc++.h>
#include<vector>
#define ll long long int
#define fr(s,e) for(ll i=s;i<e;i++)
#define mod 1000007
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // freopen("input.txt","r",stdin);
//    freopen("output1.txt","w",stdout);
    ll t,k=1;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        if(k==1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            ll r,ans;
            ans=(n / (k));
            ans%=k;
            if(ans==0)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    }
    return 0;
}




