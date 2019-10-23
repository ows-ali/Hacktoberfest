#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int x1,y1,x2,y2;
	    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	    
	    if(y1==y2)
	    {
	        if(x2>x1)
	        {
	            printf("right\n");
	        }
	        else if(x2<x1)
	        {
	            printf("left\n");
	        }
	        else
	        {
	            printf("sad\n");
	        }
	    }
	    else if(x1==x2)
	    {
	        if(y2>y1)
	        {
	            printf("up\n");
	        }
	        else if(y2<y1)
	        {
	            printf("down\n");
	        }
	        else
	        {
	            printf("sad\n");
	        }
	    }
	    else
	    {
	        printf("sad\n");
	    }
	}
	return 0;
}

