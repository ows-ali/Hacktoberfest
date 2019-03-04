#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
int main()
{
 ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    int t;
    ll p1,p2,k;
    cin>>t;
    while(t--)
    {
        cin>>p1>>p2>>k;
        ll total=(p1+p2)/k;
        if(total%2==0)
        {
            cout<<"CHEF"<<endl;
        }
        else
        {
            cout<<"COOK"<<endl;
        }
    }
return 0;
}
