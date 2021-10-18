#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Modular_Exponentiation(ll A,ll B,ll MOD)// computes (A^B)%MOD
{
    ll ans=1;
    A=A%MOD;
    while(B>0)
    {
        if(B&1) ans=(ans*A)%MOD;
        B=B>>1;
        A=(A*A)%MOD;
    }
    return ans;
}
int main()
{
  cout<<"Enter number, power and MOD\n";
  ll a,b,c;
  cin>>a>>b>>c;
  cout<<Modular_Exponentiation(a,b,c)<<"\n";
  return 0;
}
