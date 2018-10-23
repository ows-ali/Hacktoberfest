//https://www.codechef.com/FEB18/problems/CHEFPTNT

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
	long long int t,i,j,n,m,x,k;
	long long int c=0;
    t=inp();
    string s;
    while(t--){
        int ev=0,od=0,evm,odm,evp=0,odp=0;
        cin>>n>>m>>x>>k;
        cin>>s;
        ff(i,0,k){
            if(s[i]=='E')ev++;
            else od++;
        }
        if(m%2==0)
            odm=m/2;
        else
            odm=m/2+1;
        evm=m/2;
        evp=evm*x;
        odp=odm*x;
        if(ev>evp){
            ev=evp;
        }
        if(od>odp){
            od=odp;
        }
        if(ev+od>=n){
            cout<<"yes\n";
        }else
            cout<<"no\n";
    }
	
	return 0;
} 













