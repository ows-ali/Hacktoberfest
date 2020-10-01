#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;
lld find_digit(lld num){
    lld add_one = (num%9)?1:0;
    return (num/9) + add_one;
}

int main(){
    lld t;
    cin>>t;
    while(t--){
        lld pc,pr;
        cin>>pc>>pr;
        lld add_one = 0;
        lld pr_digit = find_digit(pr);
        lld pc_digit = find_digit(pc);
        if( pc_digit > pr_digit){
            cout<<"1 "<<pr_digit<<endl;
        }
        else if(pc_digit < pr_digit){
            cout<<"0 "<<pc_digit<<endl;
        }
        else{
            cout<<"1 "<<pr_digit<<endl;
        }
    }
    return 0;
}
