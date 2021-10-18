#include<iostream>
#include<math.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
using namespace std;
class crc
{
    char info[MAX];
    char gene[MAX];
    char code[MAX];
    int n;
    int c;
    int g;


public:
    void input()
    {
        cout<<"\nEnter the number of info bits::";
        cin>>n;
        cout<<"\n"<<"Enter "<<n<<" bits::";
        for(int i=0; i<n; i++)
        {
            cin>>info[i];
        }
        for(int i=0; i<n; i++)
        {
            if(info[i]=='0'||info[i]=='1')
            {
                continue;
            }
            else
            {
                cout<<"\ninvalid data";
                exit(0);
            }
        }
        cout<<"\n no of the bits in generator code::";
        cin>>g;
        cout<<"\n Enter" <<g<<" Generater bits::";
        for(int i=0; i<g; i++)
        {
            cin>>gene[i];
        }
        for(int i=0; i<g; i++)
        {
            if(gene[i]=='0'||gene[i]=='1')
            {
                continue;
            }
            else
            {
                cout<<"\ninvalid data";
                exit(0);
            }
        }
    }
    int value(char a[],int n)
    {
        int sum =0;
        for(int i=0; i<n; i++)
        {
            if(a[i]=='1')
            {
                int p = pow(2,i);
                sum +=p;
            }
        }
        return sum;
    }

    void generate()
    {
        char temp[n];
        int k = n;
        for(int i=0; i<n; i++)
        {
            temp[i] = info[i];
        }

        while(value(info,n)>value(gene,g))
        {

            if(info[0]=='0')
            {
                for(int i=1; i<n; i++)
                {
                    info[i-1] = info[i];
                }
                n--;

            }
            else
            {

                for(int i=0,j=0; i<g; i++,j++)
                {

                    info[j] =((info[j]-'0') ^ (gene[i]-'0'))+'0';
                }

            }
        }
        for(int i=0; i<n; i++)
        {
            cout<<info[i];
        }
        cout<<endl;
        int cc=0;
        for(int i=0; i<k; i++)
        {
            code[cc++] = temp[i];
        }
        while(true)
        {

            if(info[0]=='0')
            {
                for(int i=1; i<n; i++)
                {
                    info[i-1] = info[i];

                }
                n--;
            }
            else
            {
                break;
            }
        }
        for(int i=0; i<n; i++)
        {
            code[cc++] = info[i];
        }
        code[cc]='\0';
        c = cc;
        cout<<"\nCode Generated ::";
        for(int i=0; i<c; i++)
        {
            cout<<code[i];
        }
        //cout<<"*************************************";

    }
    void error()
    {
        srand (time(NULL));
        int x = rand() % 4 +1;
        cout<<endl<<x;
        for(int i=0; i<x; i++)
        {
            if(code[i]=='1')
            {
                code[i]='0';
            }
            else
            {
                code[i]='1';
            }
        }
        cout<<endl;
        for(int i=0; i<c; i++)
        {
            cout<<code[i];
        }

    }

    void check()
    {
        while(value(code,c)>=value(gene,g))
        {
            if(code[0]=='0')
            {
                for(int i=1; i<c; i++)
                {
                    code[i-1] = code[i];
                }
                c--;
                cout<<endl;

            }
            else
            {
                for(int i=0; i<g; i++)
                {
                    code[i] = ((code[i]-'0') ^ (gene[i]-'0'))+'0';
                }

            }
        }
        cout<<endl;
        int flag=1;
        for(int i=0; i<c; i++)
        {
            if(code[i]=='1')
            {
                flag=0;
            }
        }

        if(flag==1)
        {
            cout<<"\n No Error Genrated";
        }
        else
        {
            cout<<"\n Error Genrated";
        }
    }


};

int main()
{
    crc c;
    c.input();
    c.generate();
    c.error();
    c.check();
}
