#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int x=0,t;
    cin>>t;
    string s;
    //string plus = "++",minus = "--";
    while(t--){
        cin>>s;
        if(s[0]=='+' || s[2]=='+')x++;
        else x--;
    }
    cout<<x;
    return 0;
}