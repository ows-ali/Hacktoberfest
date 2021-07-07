#include <stdio.h>
#include <string.h>
int main(void) {
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    char a[25000],b[25000];
	    int m=0,n=0,k=0;
	    scanf("%s %s",a,b);
	    m=strlen(a);
	    n=strlen(b);
	    for(int j=0;j<n;j++)
	            {
	                if(b[j]==a[k])
	                    k++;
	            }
	        if(k==m)
	        printf("YES\n");
	        else
	        {
	            k=0;
	         for(int j=0;j<m;j++)
	            {
	                if(a[j]==b[k])
	                    k++;
	            }
	       
	        if(k==n)
	        printf("YES\n"); 
	       else
	        printf("NO\n");
	        }
	    
	}
	return 0;
}

