#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int a,b;
	    scanf("%d %d",&a,&b);
	    int x = a+b;
	    printf("%d %d\n",max(a,b),x);
	}
	return 0;
}

int max(int l, int y)
{
    return ((l>y)?l:y);
}
