//to find minimal moves required to climb stairs 2 or 1 at a time, so that moves is a multiple of m
#include <stdio.h>

int main()
{   
    int m,n,x;
    printf("Enter n : ");
    scanf("%d",&n);
    printf("Enter m : ");
    scanf("%d",&m);
   if(n>=m){
    x=n/2;
    while(x%m!=0){
        x++;
    }}
    else
     x=-1;
    
 printf("\nNo. of moves= %d",x);
    return 0;
}

