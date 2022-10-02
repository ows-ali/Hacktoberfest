#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n,a,t;
   cin>>n>>t;
   while(t--)
   {
        a=n%10;
        switch(a)
        {
            case 0:
                n/=10;
                break;
            default:
                n--;
        }
   }
   cout<<n;
    return 0;
}