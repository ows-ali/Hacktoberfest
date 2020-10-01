#include <stdio.h>
#include <time.h>

#ifndef ONLINE_JUDGE
#define getcx getchar
#else
#define getcx getchar_unlocked
#endif

int scan(void);

int main() {
    int i,n=scan();
    int reported[n+2];

    for(i=0;i<=n;i++)
        reported[i]=0;

    for(i=0;i<n;i++)
        reported[scan()]=1;

    for(i=0;i<=n;i++) {
        if(reported[i]==0)
            printf("%d ",i);
    }

    printf("\n");
    return 0;
}

int scan() {
    int num=0,sign=1;
    char c='\0';
    while(c<'0'||c>'9') {
        c=getcx();
        if (c=='-') {
            sign=-1;
            c=getcx();
            break;
        }
    }

    while(c>='0' && c<='9') {
        num=num*10+c-'0';
        c=getcx();
    }
    return num*sign;
}
