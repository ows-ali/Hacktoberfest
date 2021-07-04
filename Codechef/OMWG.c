#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int m,n;
	    scanf("%d %d",&m,&n);
	    
	    int l = ((m-1) * (n-1)) - 1;
	    int x = m*n;
	    printf("%d\n",x + l);
	}
	return 0;
}

