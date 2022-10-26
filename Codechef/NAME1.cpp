//https://www.codechef.com/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string allpar,par1,par2;
        cin>>par1>>par2;
        allpar=par1+par2;
        int child;
        cin>>child;
        string allname;
        for(int i=0;i<child;i++){
            string name;
            cin>>name;
            allname=allname+name;
        }
        string ans="YES";
        map<char,int> perm;
        for(char i:allpar){
            perm[i]++;
        }
        map<char,int> childname;
        for(char i:allname){
            childname[i]++;
        }
        for(auto i:childname){
            if(perm.find(i.first)==perm.end()){
                ans="NO";
            }
            else if(perm[i.first]<i.second){
                ans="NO";
            }
        }
        cout<<ans<<endl;
    }
return 0;
}