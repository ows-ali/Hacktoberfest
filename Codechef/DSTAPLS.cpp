/*
  * @authr AVINISH KUMAR
  * @college BIT MESRA
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl "\n"
typedef long long ll;
typedef double db;


int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ll t;
     cin>>t;
     while(t--)
     {
        ll n,k;
        cin>>n>>k;
        ll a=n/k;
        if(a%k==0)
        {
            cout<<"NO"<<endl;
        }
        else
        cout<<"YES"<<endl;
     }
}
