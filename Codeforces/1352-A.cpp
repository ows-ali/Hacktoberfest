#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int tmp=n,c=0,x;
        while(tmp!=0){
            x=tmp%10;
            if(x!=0)
                c++;
            tmp/=10;
        }
        cout<<c<<endl;
        c=0;
        while(n!=0){
            x=n%10;
            if(x!=0){
                int a=x*(int)pow(10,c);
                cout<<a<<endl;
            }
            c++;
            n/=10;
        }
    }
    return 0;
}