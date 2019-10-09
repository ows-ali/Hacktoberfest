#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int arr[1000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    int sum=0;
    for(i=0;i<n;i++){
        sum+=arr[i];
    }
    printf("%d",sum);
    return 0;
}

