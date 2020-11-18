#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,a,b,s;
    cin>>n>>q;
    vector<long> v(n+1,0);
    for(int i=0;i<q;i++)
    {
        cin>>a>>b>>s;
        v[a]+=s;
        if(b+1<=n)v[b+1]-=s;
    }
    long m=0,x=0;
    for(int i=1;i<=n;i++)
    {
        x=x+v[i];
        m=max(m,x);
    }
    cout<<m;
    return 0;
}

