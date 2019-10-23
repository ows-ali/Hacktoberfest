#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n,sum=0;
	    scanf("%d",&n);
	    
	    while(n!=0)
	    {
	        int rem = n % 10;
	        sum = sum + rem;
	        n = n / 10;
	    }
	    printf("%d\n",sum);
	}
	return 0;
}

