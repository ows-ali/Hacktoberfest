#include<iostream>
#include<limits.h>
using namespace std;
class worstfit
{
public:
    int allocate(int memory[],int n,int p)
    {
        int large = -1;
        int index = -1;
        for(int i=0; i<n; i++)
        {
            if(memory[i]>=p)
            {
                if(memory[i]>large)
                {
                    large = memory[i];
                    index = i;
                }
            }
        }
        return index;
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
int main()
{

    cout<<"\nEnter the no. of blocks";
    int n;
    cin>>n;
    int memory[n];
    int m2[n];
    int m3[n];
    cout<<"\nEnter "<<n<<"values";
    for(int i=0; i<n; i++)
    {
        cin>>memory[i];

    }

    cout<<"\nEnter the no. of processes";
    int m;
    cin>>m;
    int process[m];

    cout<<"\nEnter the size of "<<m<<"processes";
    for(int i=0; i<m; i++)
    {
        cin>>process[i];

    }
    cout<<"\n**********WORST FIT************************";
     worstfit f;
    f.cal(memory,n,process,m);
    cout<<endl<<"Wastage is"<<f.wastage(memory,n);

}
