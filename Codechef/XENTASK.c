#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        int a[n],b[n];
        
        for(int i=0;i<n;i++)
        {
            scanf("%d ",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d ",&b[i]);
        }
        int sum1 = 0, sum2 = 0;
        for(int i=0;i<n;i++)
        {
            if(i % 2 == 0)
            {
                sum1 += a[i];
            }
            else
            {
                sum1 += b[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i % 2 == 0)
            {
                sum2 += b[i];
            }
            else
            {
                sum2 += a[i];
            }
        }
        
        if(sum1 > sum2)
        {
            printf("%d\n",sum2);
        }
        else
        {
            printf("%d\n",sum1);
        }
    }
}
