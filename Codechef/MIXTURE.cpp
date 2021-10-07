#include<bits/stdc++.h>
using namespace std;
int main(){
int t,a,b;
cin>>t;
while(t--){
    cin>>a>>b;
    cout<<((a>0 && b>0) ? "Solution": (a==0) ? "Liquid":"Solid")<<endl;   
}
return 0;
}