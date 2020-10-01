#include <stdio.h>

void compareTriplets(int[], int[]);

int main()
{
    int a[3];            //Alice
    int b[3];            //Bob
   // int * ptsPtr;
    int i;
    
    for(i=0; i<3; i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0; i<3; i++)
    {
        scanf("%d",&b[i]);
    }

    //ptsPtr = compareTriplets(a,b);
    //printf("%d %d\n",ptsPtr[0], ptsPtr[1]);
    compareTriplets(a,b);
    return 0;
}

void compareTriplets(int a[3], int b[3])
{
    int points[2] = {0,0}; //return array
    int i;

   for(i=0; i<3; i++)
   {
       if(a[i] > b[i])
       {
           points[0] += 1;
       }

       else if(a[i] < b[i])
       {
           points[1] += 1;
       }
       else;
   }

    printf("%d %d\n",points[0], points[1]);
}
