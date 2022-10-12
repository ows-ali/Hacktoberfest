#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, x;
    cin>>t;
    while(t--){
        cin>>x;
        int c=0;
        if(x<5){
            cout<<"No"<<endl;
        }
        else if(x==5){
            cout<<"Yes"<<endl;
        }
        else{
        for(int i=1;i<=sqrt(x);i++){
            if((x-(2*i))%(2+i)==0){
                c=c+1;
                break;
            }
        }
        if(c==1){
            cout<<"Yes"<<endl;
        }
        else{
        cout<<"No"<<endl;
        }
        }
    }
    return 0;
}
    
