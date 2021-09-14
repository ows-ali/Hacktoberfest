#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int Sum(long long int a)
{
    int sum=0;
    if(a>=0 && a<=9)
    {return a;}
    while(a>0)
    {
        sum=sum+(a%10);
        a=a/10;
    }
   
    return sum;
}
int cal(int sum,long long int  n,int sum1)
{
    if(n==0)
    {return sum1;}
    n--;
    //cout<<"B"<<sum1<<endl;
    return cal(sum,n,Sum(sum*sum1));
}
int main()
{
   
    int t,i,j;
string a;
    long long int n;
    int count;
    cin>>t;
    while(t--)
    {
      cin>>n>>a;
        count=0;
        j=0;
        if(n==1)
        {cout<<"No"<<endl;
        continue;}
        for( i=0;i<n-1;i++)
        {
            if((a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U') && (a[i+1]=='A' || a[i+1]=='E' || a[i+1]=='I' || a[i+1]=='O' || a[i+1]=='U' ))
            {
                j=1;
                break;
            }
        }
        i=n-1;
               if((a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U') && (a[0]=='A' || a[0]=='E' || a[0]=='I' || a[0]=='O' || a[0]=='U' ))
                  {
                      j=1;
                  }
        if(j==0)
        {
            cout<<"No"<<endl;

        }
                  else
                  {cout<<"Yes"<<endl;}
       
    }
    return 0;
}
