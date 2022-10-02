#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,cap=0,max=cap;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        cap=cap-a+b;
        if(max<cap)
            max=cap;
    }
    cout<<max;
    return 0;
}