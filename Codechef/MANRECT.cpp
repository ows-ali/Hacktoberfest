#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//#define endl "\n"
const int mod = 1000000007;
int main()
{
   ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t;
cin>>t;

while(t--)
{
vector<ll>v;
 ll i,j,sum=0,act=0,k,n,q,x1,y1,x2,y2,k1,k2,k3,xu,yu,xv,yv,k4,k5;
 cout<<"Q 0 0"<<endl; 
cin>>k1;
cout<<"Q 0 1000000000"<<endl; 
cin>>k2;

x1=((k1+k2-1000000000)/2);
y1=((k1-k2+1000000000)/2);
cout<<"Q 0 "<<" "<<y1<<endl; 
cin>>k3;
xu=k3;
yu=k1-xu;


cout<<"Q 1000000000 1000000000"<<endl; 
cin>>k3;
cout<<"Q 1000000000 0"<<endl; 
cin>>k4;
yv=xu-k2+1000000000;

xv=(2*1000000000)-k3-yv;
cout<<"A "<<xu<<" "<<yu<<" "<<xv<<" "<<yv<<endl;
int a;
cin>>a;

}
return 0;
}
