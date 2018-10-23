//https://www.codechef.com/FEB18/problems/CARPTUN

#include <iostream>
#include <iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<algorithm>

#define ll double
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
    t=inp();
    while(t--){
        cin>>n;
        ll a[n],c,d,s,max=0;
        ff(i,0,n){
            cin>>a[i];
            if(max<a[i])max=a[i];
        }
        cin>>c>>d>>s;
        cout <<fixed;
        cout << setprecision(9);
        cout<<max*(c-1)<<endl;
    }
	
	return 0;
} 













