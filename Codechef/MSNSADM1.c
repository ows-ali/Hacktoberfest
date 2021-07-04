#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int a[n],b[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d ",&a[i]);
	    }
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d ",&b[i]);
	    }
	    
	    int c[n];
	    for(int i=0;i<n;i++)
	    {
	        c[i] = a[i]*20 - b[i]*10;
	        if(c[i]<0)
	        {
	            c[i] = 0;
	        }
	    }
	    int max_l = c[0];
	    for(int i=0;i<n;i++)
	    {
	        if(max_l < c[i])
	        {
	            max_l = c[i];
	        }
	    }
	    
	    printf("%d\n",max_l);
	}
	return 0;
}

