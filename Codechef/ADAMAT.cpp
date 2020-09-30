#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+1][n+1];
        
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>a[i][j];
        int count=0;
        
        bool loc[n+1];
        
       for(int j=1;j<=n;j++)
       {
         if(a[1][j]==j)
         loc[j]=1;
         else
         loc[j]=0;
       }
        
        int k=n;
        while(k>1)
        {
            if(loc[k]==0)
            {
                for(int i=0;i<=k;i++)
                loc[i]=!loc[i];
                count++;
                k--;
            }
            else
            k--;
        }
        
     cout<<count<<endl;
     
    }
    
   
}
