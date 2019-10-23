#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&a[i]);
	    }
	    int max = a[0],pos=0;
	    for(int i=0;i<n;i++)
	    {
	        
	        if(a[i] > max)
	        {
	            max = a[i];
	            pos = i;
	        }
	    }
	    int x = n/2,c=0;
	    for(int i=1;i<=x;i++)
	    {
	          if(a[pos-i]==a[pos+i])
	            {
	                c = c+1;
	            }
	    }
	    int l=0;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i+1]-a[i]==1)
	        {
	            l += 1;
	        }
	    }
	    
	    if(c >= x && a[0]==1 && a[0]==a[n-1] && l >= x)
	    {
	        printf("yes\n");
	    }
	    else
	    {
	        printf("no\n");
	    }
	}
	return 0;
}

