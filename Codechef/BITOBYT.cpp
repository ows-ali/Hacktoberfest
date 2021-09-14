#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
int main()
{
  int t;
  cin>>t;
  int n,b,a;
  while(t--)
  {
    cin>>n;
    a=n%26;
    b=n/26;
    if(a==0)
    {
      cout<<"0 0 "<<(ll)pow(2,b-1)<<endl;
    }
    if(a>0 && a<=2)
    {
      cout<<(ll)pow(2,b)<<" 0 0"<<endl;
    }
    if(a>2 && a<=10)
    {
      cout<<"0 "<<(ll)pow(2,b)<<" 0"<<endl;
    }
    if(a>10)
    {
      cout<<"0 0 "<<(ll)pow(2,b)<<endl;
    }
  }
return 0;
}
