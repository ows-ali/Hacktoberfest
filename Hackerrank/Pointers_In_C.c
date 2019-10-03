/**
    https://www.hackerrank.com/challenges/pointer-in-c/problem?h_r=profile
**/

#include <stdio.h>
#include <math.h>

void update(int *a,int *b) {
    // Complete this function  
    (*a) = (*a) + (*b);
    (*b) = abs((*a) - (*b) - (*b));   
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
