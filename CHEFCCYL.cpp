#include <bits/stdc++.h>
using namespace std;

//important constants
#define pi M_PI
#define mod 1000000007
#define maX(a,b)		((a)>(b)?(a):(b))
#define miN(a,b)		((a)<(b)?(a):(b))

#ifdef ONLINE_JUDGE
#define MAX 200000
#else
#define MAX 1000
#endif

int a[MAX],jumpCost[MAX],jumpV[MAX][2];
// vector<int> cycle[MAX];
vector<int> psumCycle[MAX];
int jumpSum[MAX],pjumpCost[MAX],pjumpSum[MAX];
int test;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif
	
	int t,n,m,l,flag,count,d,e,mx,mn,q,c1,c2,v1,v2;
	long long int x,y,z,k;

	scanf("%d",&test);
	while(test--){

		scanf("%d%d",&n,&q);
		// for case N=2 deal seperately as there are two jumps
		if(n==2){
			for(int i=0;i<n;i++){
				scanf("%d",&a[i]);	//	No. of vertices in ith cycle
				psumCycle[i].push_back(0);
				if(a[i]>2){
					for(int j=0;j<a[i];j++){
						scanf("%d",&d);
						// cycle[i].push_back(d);
						psumCycle[i].push_back(psumCycle[i][j]+d);/* Now we know the
						cost to travel from one vertex to another in the same cycle */
					}
				}else if(a[i]==2){
					scanf("%d%d",&d,&e);
					// cycle[i].push_back(miN(d,e));
					psumCycle[i].push_back(miN(d,e));
					psumCycle[i].push_back(psumCycle[i][1]*2); // to get the cost equal
					// forward and backward as their are only two vertices.
				}else
					scanf("%d",&d);
			}
			for(int i=0;i<n;i++)
				scanf("%d%d%d",&jumpV[i][0],&jumpV[i][1],&jumpCost[i]);

			pair<int,int> vc[2];
			while(q--){
				scanf("%d%d%d%d",&vc[0].second,&vc[0].first,&vc[1].second,&vc[1].first);
				sort(vc,vc+2);
				v1=vc[0].second-1,v2=vc[1].second-1;
				x=jumpV[0][0]-1;
				y=abs(psumCycle[0][v1]-psumCycle[0][x]);
				z=miN(y,psumCycle[0][a[0]]-y)+jumpCost[0];
				x=jumpV[0][1]-1;
				y=abs(psumCycle[1][v2]-psumCycle[1][x]);
				z+=miN(y,psumCycle[1][a[1]]-y);

				x=jumpV[1][1]-1;
				y=abs(psumCycle[0][v1]-psumCycle[0][x]);
				k=miN(y,psumCycle[0][a[0]]-y)+jumpCost[1];
				x=jumpV[1][0]-1;
				y=abs(psumCycle[1][v2]-psumCycle[1][x]);
				k+=miN(y,psumCycle[1][a[1]]-y);

				printf("%lld\n",miN(z,k));
			}
		}else if(n>2){
			for(int i=0;i<n;i++){
				scanf("%d",&a[i]);	//	No. of vertices in ith cycle
				psumCycle[i].push_back(0);
				if(a[i]>2){
					for(int j=0;j<a[i];j++){
						scanf("%d",&d);
						// cycle[i].push_back(d);
						psumCycle[i].push_back(psumCycle[i][j]+d);/* Now we know the
						cost to travel from one vertex to another in the same cycle */
					}
				}else if(a[i]==2){
					scanf("%d%d",&d,&e);
					// cycle[i].push_back(miN(d,e));
					psumCycle[i].push_back(miN(d,e));
					psumCycle[i].push_back(psumCycle[i][1]*2); // to get the cost equal
					// forward and backward as their are only two vertices.
				}else
					scanf("%d",&d);
			}
			

			pjumpCost[0]=0;
			for(int i=0;i<n;i++){
				scanf("%d%d%d",&jumpV[i][0],&jumpV[i][1],&jumpCost[i]);
				pjumpCost[i+1]=pjumpCost[i]+jumpCost[i];
			}
			// jumpV[i][0] is jump index in ith cycle and 
			// jumpV[i][1] is jump index in (i+1)th cycle


			x=miN(jumpV[0][0],jumpV[n-1][1]);
			y=maX(jumpV[0][0],jumpV[n-1][1]);
			z=psumCycle[0][y-1]-psumCycle[0][x-1];
			jumpSum[0]=min(z,psumCycle[0][a[0]]-z);
			for(int i=0;i<n-1;i++){
				x=miN(jumpV[i][1],jumpV[i+1][0]);
				y=maX(jumpV[i][1],jumpV[i+1][0]);
				z=psumCycle[i+1][y-1]-psumCycle[i+1][x-1];
				jumpSum[i+1]=min(z,psumCycle[i+1][a[i+1]]-z);
			}
		

			pjumpSum[0]=0;
			for(int i=0;i<n;i++)
				pjumpSum[i+1]=pjumpSum[i]+jumpSum[i];


			pair<int,int> vc[2];
			while(q--){
				scanf("%d%d%d%d",&vc[0].second,&vc[0].first,&vc[1].second,&vc[1].first);
				sort(vc,vc+2);
				c1=vc[0].first-1,v1=vc[0].second-1,c2=vc[1].first-1,v2=vc[1].second-1;
				
				
				// forward cost
				z=(pjumpSum[c2]-pjumpSum[c1+1])+(pjumpCost[c2]-pjumpCost[c1]);
				x=jumpV[c1][0];
				y=abs(psumCycle[c1][x-1]-psumCycle[c1][v1]);
				z+=miN(y,psumCycle[c1][a[c1]]-y);
				x=jumpV[c2-1][1];
				y=abs(psumCycle[c2][x-1]-psumCycle[c2][v2]);
				z+=miN(y,psumCycle[c2][a[c2]]-y);
		
				// backward cost
				k=(pjumpSum[n]-(pjumpSum[c2]-pjumpSum[c1+1])-(jumpSum[c2]+jumpSum[c1]))+pjumpCost[n]-(pjumpCost[c2]-pjumpCost[c1]);
				// printf("k=%lld ",k);
				x=jumpV[(c1+n-1)%n][1];
				y=abs(psumCycle[c1][x-1]-psumCycle[c1][v1]);
				k+=miN(y,psumCycle[c1][a[c1]]-y);
				x=jumpV[c2][0];
				y=abs(psumCycle[c2][x-1]-psumCycle[c2][v2]);
				k+=miN(y,psumCycle[c2][a[c2]]-y);
				z=miN(z,k);
				printf("%lld\n",z);
			}
		}
		for(int i=0;i<n;i++)
			psumCycle[i].clear();
	}
	return 0;
}
