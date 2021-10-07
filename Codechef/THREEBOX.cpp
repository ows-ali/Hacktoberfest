#include<bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
FastIO;
int t,a,b,c,d;
cin>>t;
while(t--){
    cin>>a>>b>>c>>d;
    cout<<((a+b+c <= d)?'1':(a+b <=d || b+c <=d || c+a<=d)?'2':'3')<<endl;   
}
return 0;
}