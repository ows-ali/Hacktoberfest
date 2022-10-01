#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char str[1000], begin='0';
    scanf("%s", str);

    int len = strlen(str), count=0;
    for(int i=0; i<10; i++)
    {
        count = 0;
        for(int j=0; j<len; j++)
        {
            if (str[j] == begin) count++;
        }
        printf("%d ", count);
        begin++;
    }
    return 0;
}
