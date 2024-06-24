#include <bits/stdc++.h>
using namespace std;
int main(){
    char s[11],s1[11];
    cin>>s;
    for(int i=0;i<10;i++)
    s1[i]=s[i];
    if(s[8]=='P'&&(s[1]=='8'||s[1]=='9'))
    {
    s1[0]+=2;
    s1[1]-=8;
    }
    else if(s[8]=='P'&&s[0]=='1'&&s[1]=='2')
    {
        s1[0]=s1[0];
        s1[1]=s1[1];
    }
    else if(s[8]=='P')
    {
        s1[0]+=1;
        s1[1]+=2;
    }
    if(s[8]=='A'&&s[0]=='1'&&s[1]=='2')
    {
        s1[0]='0';
        s1[1]='0';
    }
     for(int i=0;i<8;i++)
     cout<<s1[i];
}
