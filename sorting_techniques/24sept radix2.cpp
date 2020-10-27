#include<iostream>
using namespace std;
int getmax(int a[],int n)
{
    int m=a[0];
    for(int i=1;i<n;i++)
    {
        if(m<a[i])
            m=a[i];
    }
    return m;
}
void countsort(int a[],int n,int exp)
{
    int c[10]={0};
    int o[30];
    for(int i=1;i<n;i++)
    {
        c[(a[i]/exp) %10 ]++;
    }
    for(int i=1;i<10;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        o[ c[(a[i]/exp) %10 ] - 1]=a[i];
        c[ (a[i]/exp) % 10 ]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = o[i];


}
void radix(int a[],int n)
{
    int maxd=getmax(a,n);
    for(int exp=1;maxd/exp>0;exp=exp*10)
        countsort(a,n,exp);
}

int main()
{
    int n,a[30],i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    radix(a,n);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
