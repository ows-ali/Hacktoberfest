#include<iostream>
#include<limits.h>
using namespace std;
class firstfit
{

public:

    int allocate(int memory[],int n,int p)
    {
        for(int i=0; i<n; i++)
        {
            if(memory[i]>=p)
            {
                return i;
            }
        }
        return -1;
    }
    void cal(int memory[],int n,int process[],int m)
    {
        for(int i=0; i<m; i++)
        {
            int mi = allocate(memory,n,process[i]);
            if(mi!=-1)
            {
                memory[mi] -= process[i];

                cout<<"\nmemory to process:"<<i<<":given in block:"<<mi;
                process[i] = 0;
            }
        }

        for(int i=0; i<m; i++)
        {
            if(process[i]>0)
            {
                cout<<"\nprocess "<<i<<" not allocated memory";
            }
        }

    }
    int wastage(int a[],int n)
    {
        int c =0;
        for(int i=0; i<n; i++)
        {
            c += a[i];
        }
        return c;
    }
};
