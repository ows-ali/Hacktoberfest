#include <stdio.h>

//Original problem url: https://www.urionlinejudge.com.br/judge/en/problems/view/1371
//To see other problems, change the ending number to its problem number

int main()
{
    int n;

    while(true)
    {
        scanf(" %d",&n);
        if(n==0)
            return 0;
        printf("1");
        for(int i=2;i*i<=n;i++)
            printf(" %d",i*i);
        printf("\n");
    }

    return 0;
}
