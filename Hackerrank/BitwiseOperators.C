#include <stdio.h>
void calculate_the_maximum(int n, int k) 
{ 
    int a,b,c,max=0,ma=0,m=0;
  for(int i=1;i<=n-1;i++)
  {
      for(int j=i+1;j<=n;j++)
      {
          a = i & j;
          b= i|j;
          c=i^j;
          if(a>max && a<k)
          max=a;
          else
          max=max;
          if(b>m && b<k)
          m=b;
          else 
          m=m;
          if(c>ma && c<k)
          ma=c;
          else  
          ma=ma;
      }
  }
  printf("%d\n",max);
   printf("%d\n",m);
    printf("%d\n",ma);
}
int main() 
{
    int n, k;
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n,k);
    return 0;
}
