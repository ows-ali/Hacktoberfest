#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t!=0)
    {
        long n,summ=0,m=-1,pos=-1;
        cin>>n;
        long long a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            summ=summ+a[i];
        }
        if(summ%n==0)
            m=summ/n;
        for(int i=0;i<n;i++)
        {
            if(a[i]==m){
                pos=i+1;
                break;
            }
        }
        if(pos>-1)
            cout<<pos<<endl;
        else
            cout<<"Impossible"<<endl;
        t--;
    }
    
}