#include <stdio.h>
#include<string.h>
int main(void) {
	// your code goes here
	
	int t,s,n,i;
	scanf("%d",&t);
    char st[1001];

	while(t--)
	{
	    scanf("%s",st);
	    s = 0;
	    n = strlen(st);
	    for(i=0;i<n;i++)
	    {
	        if(st[i]>='0' && st[i]<='9')
	        {
	            s+=(st[i]-48);
	        }
	    }
	    printf("%d\n",s);
	}
	return 0;
}

