#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n,rev=0,x;
	    scanf("%d",&n);
	    x = n;
	    
	    while(n!=0)
	    {
	        int rem = n%10;
	        n = n / 10;
	        rev = rev * 10 + rem;
	    }
	    
	    if(x==rev)
	    {
	        printf("wins\n");
	    }
	    else
	    {
	        printf("losses\n");
	    }
	}
	return 0;
}

