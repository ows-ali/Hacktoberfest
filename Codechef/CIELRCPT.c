#include <stdio.h>
#include<math.h>

int main(void) {
	// your code goes here
	int t,c;
	scanf("%d",&t);
	
	while(t--)
	{
	    c = 0;
	    int n;
	    scanf("%d",&n);
	    
	    while(n>0)
	    {
	        int k = pow(2,((int)log2((double)n)));
	        
	        if(k>2048)
	        {
	            k=2048;
	        }
	        while(n>=k)
	        {
	            n = n-k;
	            c++;
	        }
	    }
	    printf("%d\n",c);
	}
	return 0;
}

