#include<bits/stdc++.h>
using namespace std;

void compareTriplets(int a[3],int b[3])
{
  int res[2]={0,0};
  for(int i=0;i<3;i++)
  {
      if(a[i]>b[i])
      {
          res[0]++;
      }
      if(a[i]<b[i])
      res[1]++;
  }
  for(int i=0;i<2;i++)
  cout<<res[i]<<" ";
}
int main()
{

int a[3],b[3],i,c[2];
for(i=0;i<3;i++)
cin>>a[i];
for(i=0;i<3;i++)
cin>>b[i];
compareTriplets(a,b);
return 0;
}
