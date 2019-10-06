#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int s,t,a,b,m,n,i,count1=0,count2=0;
    int app[100000], orr[100000];
    scanf("%d %d\n", &s,&t);
    scanf("%d %d\n", &a,&b);
    scanf("%d %d\n", &m,&n);

    for(i=0;i<m;i++)
    {
        scanf("%d", &app[i]);
        
    }
    for(i=0;i<m;i++)
    {
        if (s <= a+app[i] && a+app[i] <= t)
          count1++;
    }

    for(i=0;i<n;i++)
    {
        scanf("%d", &orr[i]);
        
    }
    for(i=0;i<n;i++)
    {
        if (s <= b+orr[i] && b+orr[i] <= t)
          count2++;
    }
    
    printf("%d\n%d", count1, count2);
}
