 #include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int 

int main(){
	int  T;
	cin>>T;
	while(T--){
		char s[1000001];
		scanf("%s",s);
		ll U=0,R=0,L=0,D=0,x1,x2,y1,y2,i;
		scanf("%lld %lld",&x1,&y1);
		//cin>>x1>>y1;
		
		ll Q;
		//cin>>Q;
		scanf("%lld",&Q);
		ll n=strlen(s);
		//cout<<n<<"sushil\n";
		for(i=0;i<n;i++){
			if(s[i]=='R') R++;
			else if(s[i]=='U') U++;
			else if(s[i]=='D') D++;
			else L++;
		}
		for(i=0;i<Q;i++){
			scanf("%lld %lld",&x2,&y2);
			bool xD=false,yD=false;
			ll  xL=0,yL=0;
			if((x2-x1)>=0 && (x2-x1)<=R){ 
				xD=true;  xL=(x2-x1);
			 }
			else if( (x1-x2)>=0 && (x1-x2)<=L){
				 xD=true;  xL=(x1-x2); 
			}
			
			if((y2-y1)>=0 && (y2-y1)<=U){ yD=true;  yL=(y2-y1); }
			else if( (y1-y2)>=0 && (y1-y2)<=D) { yD=true;  yL=(y1-y2); }
			ll len=xL+yL;
			if(xD && yD){
				printf("YES %lld\n",len);
				//cout<<"YES "<<len<<endl;
				
			}
			else
				printf("NO\n");
				//cout<<"NO\n";
		}
		
	}
return(0);
}