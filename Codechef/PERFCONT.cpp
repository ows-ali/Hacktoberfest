//https://www.codechef.com/OCT17/problems/PERFCONT

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
	long long int t,i,j,n,p;
	long long int c=0,d=0;
    t=inp();
    while(t--){
        c=d=0;
        cin>>n>>p;
        ff(i,0,n)
            {
            cin>>j;
            if(j>=p/2){
                c++;
            }
            else if(j<=p/10){
                d++;
            }
            }
        if(d==2 && c==1)cout<<"yes\n";
            else cout<<"no\n";
    }
	
	return 0;
} 













