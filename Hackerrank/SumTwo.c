#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
int a, b;
  float m, n;
  scanf("%d %d", &a, &b);
  scanf("%f %f", &m, &n);
  int sumone = a + b;
  int diffone = a - b;
  float sumtwo = m + n;
  float difftwo = m - n;
  printf("%d %d\n", sumone, diffone);
  printf("%.1f %.1f", sumtwo, difftwo);
    return 0;
}