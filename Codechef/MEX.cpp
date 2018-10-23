//https://www.codechef.com/OCT17/problems/MEX

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
	long long int t,i,j,n,max,k,ans;

    t=inp();
    while(t--){
        long long int c[200005]={0};
        max=-1;
        cin>>n>>k;
        ff(i,0,n){
            cin>>j;
            c[j]=1;
            max=max<j?j:max;
        }
        ff(i,0,max+3){
            if(k==0 && c[i]==0){
                ans=i;
                break;
            }
            else if(c[i]==0){
                k--;
            }
        }
        cout<<ans<<endl;
    }
	
	return 0;
} 













