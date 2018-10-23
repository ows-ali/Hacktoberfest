//https://www.codechef.com/FEB18/problems/CHEFCHR

#include <iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<algorithm>

#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define ff(i,a,n) for(i=a;i<n;i++)

using namespace std;

inline int inp() {  
 int n=0;  
 char p=getchar_unlocked();  
 while((p<'0'||p>'9')&&p!=EOF)  
 p=getchar_unlocked();  
 while(p>='0'&&p<='9')  
 {  
 n = (n<< 3) + (n<< 1) + (p - '0');  
 p=getchar_unlocked();}  
 return n;}  
 
int main() {
	long long int t,i,j,n;
	long long int c=0;
	set<char> alpha;
	string s;
    t=inp();
    while(t--){
        int ans=0;
        cin>>s;
        for(i=0;i<s.size();i++){
            alpha.clear();
            if(s[i]=='c' || s[i]=='h' || s[i]=='e' || s[i]=='f'){
                ff(j,i,i+4){
                    if(s[j]=='c' || s[j]=='h' || s[j]=='e' || s[j]=='f'){
                         alpha.insert(s[j]);
                    }
                    else{
                        break;
                    }
                }
                if(alpha.size()==4){
                    ans++;
                }
            }
        }
        if(ans>0)
        cout<<"lovely "<<ans<<endl;
        else
        cout<<"normal"<<endl;
    }
	
	return 0;
} 













