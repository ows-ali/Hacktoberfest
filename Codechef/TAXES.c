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
	    if(m>100)
	    m=m-10;
	    i++;
	    printf("%d\n",m);
	}
	 
	return 0;
}

