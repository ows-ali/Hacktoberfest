/*-------enazuma11----------------*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define inc(a,n) sort(a,a+n)
#define dec(a,n) sort(a,a+n,greater<int>() )
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--)
#define F first
#define S second
#define M 1000000007

int main()
{
	ll t=1;
	cin>>t;
	while(t--){
		//cout<<t<<":: ";
		ll n;
		cin>>n;
		double k[n],c[n];
		ll ki=0,ci=0;
		ll i,j;
		rep(i,0,n){
			cin>>k[i];
			if(k[i]!=1)
			ki=1;
		}
		rep(i,0,n){
			cin>>c[i];
			if(c[i]!=0)
			ci=1;
		}
		double sm =0;
		rep(i,0,n){
			sm+=k[i]*c[i];
		}
		if(sm<0){
			cout<<-1<<'\n';
			continue;
		}
		if(ci==0){
			cout<<0<<' ';
			rep(i,0,n){
				cout<<0<<" ";
			}
			cout<<'\n';
			continue;
		}
		if(n==2){
			double x[2];
			double num=c[1]*k[1]*k[1]-k[0]*k[0]*c[0];
			double den = k[0]*k[0]+k[0]*k[1];
			 x[0]=num/den;
			num=k[0]*k[0]*c[0]-k[1]*k[1]*c[1];
			den=k[1]*k[1]+k[0]*k[1];
			x[1]=num/den;
			double mx=sqrt(x[0]+c[0])+sqrt(x[1]+c[1]);
			cout<<fixed<<setprecision(10)<<mx<<" ";
			cout<<fixed<<setprecision(10)<<x[0]<<" "<<x[1]<<'\n';
			continue;
		}
		if(ki==0){
			double s=0;
			rep(i,0,n){
			s+=c[i];	
			}
			double avg=s/n;
			//cout<<avg<<" :";
			double x[n];
			rep(i,0,n){
				x[i]=-c[i];
				if(c[i]==0)
				x[i]+=avg;
				else if(x[i]>0)
				x[i]+=avg;
				else
				x[i]+=avg;
			}
			double mx=0;
			rep(i,0,n){
				mx+=sqrt(x[i]+c[i]);
			}
			cout<<fixed<<setprecision(10)<<mx<<" ";
			rep(i,0,n)
			cout<<fixed<<setprecision(10)<<x[i]<<" ";
			cout<<'\n';
			continue;
		}
		ll lst=0;
		rep(i,0,n){
			if(k[i]==0){
				lst=1;
				break;
			}
		}
		if(lst){
			cout<<-1<<'\n';
			continue;
		}
		double p=0;
		rep(i,0,n)
		p+=1/k[i];
		double num=0;
		rep(i,0,n){
			num+=k[i]*c[i];
		}
		double C=num/p;
		double x[n];
		rep(i,0,n){
			x[i]=C/(k[i]*k[i])-c[i];
		}
		double mx=0;
		rep(i,0,n){
			mx+=sqrt(x[i]+c[i]);
		}
		cout<<fixed<<setprecision(10)<<mx<<" ";
		rep(i,0,n)
		cout<<fixed<<setprecision(10)<<x[i]<<" ";
		cout<<'\n';
	}
	return 0;
}