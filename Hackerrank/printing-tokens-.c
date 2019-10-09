#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    int i;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    
    //Write your logic to print the tokens of the sentence here.
    for( i=0;i<strlen(s);i++){
        if(s[i]!=' ')
         printf("%c",s[i]);
         
          else
          printf("\n");
       }
    return 0;
}

