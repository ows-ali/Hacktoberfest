#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;
 
#define gc getchar_unlocked
 
typedef unsigned long long ull;
 
void scanint(int &x);
void scanlong(ull &x);


//C++ solution to Trace of Matrix
 
int main()
{
    int noOfTestCase;
    scanint(noOfTestCase);
    for(int i=0; i<noOfTestCase; ++i)
    {
        int nVal;
        scanint(nVal);
        int arr[nVal][nVal];
        int sum = 0;
        for(int i=0;i<nVal;++i)
        {
            for(int j=0;j<nVal;++j)
            {
                scanint(arr[i][j]);
                if(sum < arr[i][j])
                    sum = arr[i][j];
            }
        }
        
        for(int i=1;i<nVal;++i)
        {
            for(int j=1;j<nVal;++j)
            {
                arr[i][j] += arr[i-1][j-1];
                if(sum < arr[i][j])
                    sum = arr[i][j];
            }
        }
        /*printf("\n");
        for(int i=0;i<nVal;++i)
        {
            for(int j=0;j<nVal;++j)
                printf("%d ",arr[i][j]);
            printf("\n");
        }*/
        
        printf("%d\n",sum);
                
    } 
    return 0;
}
 
void scanint(int &x)
{
        int flag=0;
        register int c = gc();
        if(c == '-') flag=1;
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
        if(flag == 1)x=-x;
}
 
void scanlong(ull &x)
{
        int flag=0;
        register int c = gc();
        if(c == '-') flag=1;
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
        if(flag == 1)x=-x;
}