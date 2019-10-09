#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, b;
    float c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%f", &c);
    scanf("%f", &d);
    int sumInt = a+b;
    int sumFloatToInt = a-b;
    float sumFloat = c+d;
    float absul= c-d;
    printf("%d %d\n", sumInt, sumFloatToInt);
    printf("%0.1f %0.1f", sumFloat, absul);


    return 0;
}
