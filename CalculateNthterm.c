#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c)
 {
  int t,i=0;
  t = a+b+c;
  if(n==0)
  return i;
  else if(n==1)
  return a;
  else if(n==2)
  return b;
  else if(n==3)
  return c;
  else if(n==4)
  return t;
  else
  return find_nth_term(n-1,b,c,t);
  return 0;
}

int main()
{
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
    printf("%d", ans); 
    return 0;
}
