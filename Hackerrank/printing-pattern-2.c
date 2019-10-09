#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX(a,b) ((a>b?a:b)) //defining MAX
int main() 
{

    int n;
    scanf("%d", &n);
    for( int i=-n+1;i<n;i++) 
    {
        for(int j=-n+1;j<n;j++)
        printf("%d ",MAX(abs(i),abs(j))+1);
    printf("\n");
    }
      return 0;
}

/*
Output: If n=7, the output looks like

7 7 7 7 7 7 7 7 7 7 7 7 7 
7 6 6 6 6 6 6 6 6 6 6 6 7 
7 6 5 5 5 5 5 5 5 5 5 6 7 
7 6 5 4 4 4 4 4 4 4 5 6 7 
7 6 5 4 3 3 3 3 3 4 5 6 7 
7 6 5 4 3 2 2 2 3 4 5 6 7 
7 6 5 4 3 2 1 2 3 4 5 6 7 
7 6 5 4 3 2 2 2 3 4 5 6 7 
7 6 5 4 3 3 3 3 3 4 5 6 7 
7 6 5 4 4 4 4 4 4 4 5 6 7 
7 6 5 5 5 5 5 5 5 5 5 6 7 
7 6 6 6 6 6 6 6 6 6 6 6 7 
7 7 7 7 7 7 7 7 7 7 7 7 7 

*/