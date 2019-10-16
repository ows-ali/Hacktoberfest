//this solution includes adding the math.h

#include <stdio.h>
#include <math.h>


void update(int *a,int *b) {
      *a = *a + *b; 
      *b = abs(*a - *b - *b); //undo the adding b from previous. 
}
int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}