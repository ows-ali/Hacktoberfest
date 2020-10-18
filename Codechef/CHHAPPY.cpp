#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int t;
    cin>>t;
    while(t--)
    {
      long long int temp[100001]={0}, c=0,n,a[100001],i,j,v=0,b[100001]={0};
      c=0;
      cin>>n;
      for(i=1;i<=n;i++)
       {
           cin>>a[i];
       }
      for(i=1;i<=n;i++)
      {
          temp[a[i]]++;
      }
      for(i=1;i<=n;i++)
      {
        if(temp[i]>0)
        {
            b[a[i]]++;
        }
      }
      for(i=1;i<=n;i++)
      {
        if(b[i]>1)
        {
            c=1; break;
        }
      }
      if(c==1)
      {
          cout<<"Truly Happy\n";
      }
      else
      {
          cout<<"Poor Chef\n";
      }
    }
    return 0;
}
