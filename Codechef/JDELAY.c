#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,count=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            int si,ji;
            scanf("%d%d",&si,&ji);
            if(ji-si>5)
                count++;
        }printf("%d\n",count);
    }
    return 0;
}
