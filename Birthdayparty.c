#include<bits/stdc++.h>
using namespace std;
int prime(int N)
{
    int i,j,c=0;int a[]={2,3,5,7,11,13,17,19};
    for(i=2;i<=N;i++)
    {
        for(j=0;j<8;j++)
        if(i%a[j]==0)
        {
            c++;
            break;
        }
    }
}
int main()
{
    int T,i,N;
    cin>>T;
    for(i=0;i<T;i++)
    {
        cin>>N;
        cout<<prime(N);
    }

}
