//https://www.hackerrank.com/challenges/time-conversion/problem
  

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

int power(int base, int exponent)                 //Raise a given integer to the given exponent and return the integer result
{
    int result=1;
    for(exponent; exponent>0; exponent--)
    {
        result = result * base;
    }
    return result;
}

char* ItS(int n,int size)                         //Converts any Integer to a Corresponding String.
{
    char *_str1;
    int i=size-1;
    _str1=(char*)malloc(size*sizeof(char));
    while(n!=0)
    {
        _str1[i]=(char)(48+(n%10));
        i--;
        n/=10;
    }
    return _str1;
}

int StI(char* _str2,int size)           //Converts any String to an Corresponding Integer.
{
    int n=0;
    char ch;
    for(int i=size-1;i>=0;i--)
    {
        ch=_str2[i];
        n+=(ch-'0')*((int)power(10,size-i-1));
    }
    return n;
}

char* timeConversion(char* s)           //Converts a 12hr time to 24hr time.
{
    static char str[9];
    str[8]='\0';
    char hh[2]={s[0],s[1]};
    char mm[2]={s[3],s[4]};
    char ss[2]={s[6],s[7]};
    char m[2]={s[8],s[9]};
    int hrs=StI(hh,2);
    if(!strcmp(s,"12:00:00AM"))
    {
        return strcpy(str,"00:00:00");
    }
    else if(!strcmp(s,"12:00:00PM"))
    {
        return strcpy(str,"12:00:00");
    }
    else if(m[0]=='A')
    {
        for(int i=0;i<=7;i++)
            str[i]=s[i];
        if(hrs==12)
        {
            str[0]='0';
            str[1]='0';
        }
        return str;
    }
    else
    {
        if(hrs==12)
        {
            str[0]='1';
            str[1]='2';
        }
        else
        {
            strcpy(str,ItS((12+StI(hh,2)),2));
        }
        str[2]=':';
        str[3]=mm[0];
        str[4]=mm[1];
        str[5]=':';
        str[6]=ss[0];
        str[7]=ss[1];
        return str;
    }
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
