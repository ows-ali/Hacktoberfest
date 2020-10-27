#include<iostream>
using namespace std;
void selectionsort(int a[],int s)
{
    int m=a[0],i,j,k=0;
    for (i=0;i<s;i++)
    { m=a[i];
        for(j=i;j<s;j++)
        {
            if(m>=a[j])
            {
                m=a[j];
                k=j;

            }
        }
        int temp=a[i];
         a[i]=m;
         a[k]=temp;
    }
    for (i=0;i<s;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int a[100],i,j,m,s;
    cin>>s;
    for(i=0;i<s;i++)
    {
        cin>>a[i];
    }
    selectionsort(a,s);

}
