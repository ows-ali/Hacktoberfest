#include <stdio.h>

int main(void) {
	int T;
	scanf("%d",&T);
	while(T--)
	{
	    long long int n;
	    scanf("%lld",&n);
	    float p=0.0;
	    if(n>=5)
	    {
	        p=1;    
	    }
	    else
	    {
	        p=(n+2)/7.0;
	    }
	    printf("%f\n",p);
	}
	return 0;
}

