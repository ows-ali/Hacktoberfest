#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int r=n;
        int count=0;
        float k;
        while(r>0)
        {
            k=sqrt(r);
            if(floor(k)==ceil(k))
            {
                count++;
                r=n-r;
                n=r;
            }
            else
            {
                r--;
            }
        }
        cout<<count<<endl;
    }
}
