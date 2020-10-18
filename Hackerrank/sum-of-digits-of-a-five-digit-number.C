/*
	Name: Yogesh Singh Nayal
	Problem: Sum of digits of a five digit number
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n, i, rem, sum = 0;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    for(i = 0 ; i < 5 ; i++)
    {
        rem = n%10 ;
        sum = sum + rem ;
        n = n/10 ;
    }
    printf("%d", sum) ;
    return 0;
}

