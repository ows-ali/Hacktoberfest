#include<iostream>
using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    string str;
    while(n--)
    {
        cin>>str;
        switch(str[0])
        {
            case 'T':ans+=4;break;
            case 'C':ans+=6;break;
            case 'I':ans+=20;break;
            case 'O':ans+=8;break;
            case 'D':ans+=12;break;
            default:break;
        }
    }
    cout<<ans<<endl;
    return 0;
}