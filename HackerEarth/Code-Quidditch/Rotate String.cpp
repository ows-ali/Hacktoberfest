/* This program is from Code-Quidditch

https://www.hackerearth.com/challenges/college/Code-Quidditch/algorithm/4e4b61ed72e04e88aa9824c0e774e62f/
*/

//Program

#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,count=0,k,q,i;
    cin>>n;
    char a[n],c;
    cin>>a;
    cin>>q;
    while(q--)
    {
        cin>>c>>k;
        if(c=='l')
        {
            count-=k;
        }
        else
        {
            count+=k;
        }
    }
    if(count>=0)
    {
        count=count%n;
        for(i=n-count;i<n;i++)
        {
            cout<<a[i];
        }
        for(i=0;i<n-count;i++)
        {
            cout<<a[i];
        }
    }
    if(count<0)
    {
        count=-count;
        count=count%n;
        for(i=count;i<n;i++)
        {
            cout<<a[i];
        }
        for(i=0;i<count;i++)
        {
            cout<<a[i];
        }
    }
}
