#include <bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
    string n;
    cin>>n;
    int count=0;
    while(n!="")
    {
        int a=n[0];
        if(a=='7' || a=='4')
            count++;
        n=n.substr(1);
    }
    if(count==4||count==7)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}