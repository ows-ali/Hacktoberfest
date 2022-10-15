 
#include <stdio.h>

int main(void) {
	// your code goes 
	
	int T;int X;
	scanf("%d",&T);
	int i=1;
	
	while(i<=T)
	{
	    
	    scanf("%d",&X);
	    int m=X;
	    i++;
	     if(X>=67&&X<=45000)
	     printf("YES\n");
	     else 
	     printf("NO\n");
	}
	 
	return 0;
}
