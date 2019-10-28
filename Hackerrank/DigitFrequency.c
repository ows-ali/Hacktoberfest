#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char s[1000];
    scanf("%s",s);
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,l=0;
    for(int j=0;j<strlen(s);j++)
    {   
        {int k=(s[j]);
        switch(k)
        {   case '0':l+=1;
            break;
            case '1':a+=1;
            break;
            case '2':b+=1;
            break;
            case '3':c+=1;
            break;
            case '4':d+=1;
            break;
            case '5':e+=1;
            break;
            case '6':f+=1;
            break;
            case '7':g+=1;
            break;
            case '8':h+=1;
            break;
            case '9':i+=1;
            break;

        }
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d",l,a,b,c,d,e,f,g,h,i);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
