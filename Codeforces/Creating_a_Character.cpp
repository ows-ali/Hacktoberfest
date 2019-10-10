// problem url https://codeforces.com/contest/1217/problem/A

#include<iostream>
using namespace std;
typedef unsigned int ui;
ui res(ui st,ui in,ui ex){
    ui min = 0;
    ui max = ex;
    ui mid = max;
    //ui nmid = min;
    bool greater = st+ex>in;
    while(greater){
        if(st+(ex-mid)>in+(mid)){
            min = mid;
            mid = (min+max)/2;
            //greater = true;
            
        }
        else if(st+(ex-mid)<=in+(mid)){
            max = mid;
            mid = (min+max)/2;
            //greater = false;
        }
        if(mid == min){
            break;
        }
    }

    if(greater){
        return mid+1;
    }
    else{
        return 0;
    }

}
int main(){
    ui t;
    cin>>t;
    ui r[t];
    ui st[t],in[t],ex[t];
    for (int i = 0;i<t;i++){
        
        cin>>st[i]>>in[i]>>ex[i];
        
    }
    for (int i = 0;i<t;i++){
        r[i] = res(st[i],in[i],ex[i]);   
    }
    
    
    for (int i = 0;i<t;i++){
        cout<<r[i]<<"\n";   
    }
}