#include<iostream>
using namespace std;
int main(){
    string str;
    cin>>str;
    for(int i = 0; i < str.length(); i++){
        if(str[i]==','){
            str[i] = {'\n'};
        }
    }
    cout<<str;
    return 0;
}
