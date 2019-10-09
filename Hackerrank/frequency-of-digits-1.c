#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    char s[1000];
    int i,a[]={0,0,0,0,0,0,0,0,0,0};
    scanf("%[^\n]",&s);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='0')
        a[0]++;
        else if(s[i]=='1')
        a[1]++;
        else if(s[i]=='2')
        a[2]++;
        else if(s[i]=='3')
        a[3]++;
        else if(s[i]=='4')
        a[4]++;
        else if(s[i]=='5')
        a[5]++;
        else if(s[i]=='6')
        a[6]++;
        else if(s[i]=='7')
        a[7]++;
        else if(s[i]=='8')
        a[8]++;
        else if(s[i]=='9')
        a[9]++;
        
    }

    for(i=0;i<=9;i++){
        printf("%d ",a[i]);
    }  
    return 0;
}
