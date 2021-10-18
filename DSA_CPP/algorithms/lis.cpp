#include<bits/stdc++.h>
using namespace std;
int liscnt(int ar[],int n)
{
    int lis[n],i,j,maxi;
    for(i=0;i<n;i++)
        lis[i]=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(ar[i]>ar[j]&&lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    maxi=0;
    for(i=0;i<n;i++)
    {
        if(lis[i]>maxi)
            maxi=lis[i];
    }
    return maxi;
}
int main()
{
    int ar[8]={10,22,9,33,21,50,41,60};
    cout<<liscnt(ar,8);

return 0;
}
