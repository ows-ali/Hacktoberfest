#include<stdio.h>
int main()
{
    int t;
    float N,f;
    int i=0;
    scanf("%d",&t);
    while(i<t)
    {
        scanf("%f" ,&N);
		if(N>5)
        {
            f = 1;
        }
        else if(N<=5)
        {
            f= ((N+2)/7);
        }
        printf("%f \n",f);
        i++;
    }
return 0;    
}
