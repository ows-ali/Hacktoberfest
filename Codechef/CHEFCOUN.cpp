//https://www.codechef.com/OCT17/problems/CHEFCOUN

#include <iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector> 
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define ff(i,a,n) for(i=a;i<n;i++)
#define pp push_back
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
 
int wrongSolver(std::vector <unsigned int> a) {
	int n = a.size();
	std::vector<unsigned int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	unsigned int mn = prefSum[0] + sufSum[0];
//ll mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		unsigned int val = prefSum[i] + sufSum[i];
		//ll val = prefSum[i] + sufSum[i];
		if (val < mn) {
		  //  cout<<mn<<" "<<where<<endl;
			mn = val;
			where = i + 1;
		}
	}
	return where;
}
int main() {
	long long int t,i,j,n,h1,h2,k,x,y,z;
	long long int c=0;
	
    t=inp();
    while(t--){
        vector<unsigned int> a;
        cin>>n;
        if(n%2==0){
            h1=(n-2)/2;
            h2=h1;
        }else{
            h1=(n-2)/2;
            h2=n-2-h1;
        }
        //a.pp(10);
        cout<<"10 ";
        j=2147483648;
        k=4294967296;
        ff(i,0,h1){
            x=j/h1;
           // a.pp(x);
           cout<<x<<" ";
        }
        ff(i,0,h2){
            y=(k-(x*h1))/h2;
            a.pp(y);
            cout<<y<<" ";
        }
        z=k-h2*y-h1*x;
        if(z%2==0)
            z/=2;
        else
            z=z/2+1;
        //a.pp(z);
        cout<<z<<endl;
        //a.pp(j-1);
        //cout<<wrongSolver(a)<<" "<<endl; //expected o/p= n-2
    }
	
	return 0;
} 













