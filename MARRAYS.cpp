#include <bits/stdc++.h>
using namespace std;

//important constants
#define pi M_PI
#define mod 1000000007
#define maX(a,b)		((a)>(b)?(a):(b))
#define miN(a,b)		((a)<(b)?(a):(b))

#ifdef ONLINE_JUDGE
#define MAX 2000005
#else
#define MAX 100000
#endif

int a[MAX],r[MAX][4];
vector<int> dish[MAX];
long long int dp[MAX][4],dpM[MAX][4];
int test,n;

int find(int k,int j){
	int x=dpM[j][k];
	for(int i=0;i<dish[j].size();i++){
		if(dish[j][i]==x)
			return i;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif
	
	int m,k,l,x,y,z,flag,count,mx,mn,d;
	long long int sum;

	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			for(int j=0;j<a[i];j++){
				scanf("%d",&x);
				dish[i].push_back(x);
			}
		}

		if(n==1){
			printf("%d\n",0);
		}else{
			for(int i=1;i<n-1;i++){
				dpM[i][0]=dpM[i][1]=dpM[i][2]=dpM[i][3]=-10000000000000000;
				for(int j=0;j<a[i];j++){
					k=(j+a[i]-1)%a[i];
					if(dpM[i][0]<(1ll*i*dish[i][j]+1ll*(i+1)*dish[i][k]))
						dpM[i][0]=1ll*i*dish[i][j]+1ll*(i+1)*dish[i][k],r[i][0]=j;

					if(dpM[i][1]<(1ll*i*dish[i][j]-1ll*(i+1)*dish[i][k]))
						dpM[i][1]=1ll*i*dish[i][j]-1ll*(i+1)*dish[i][k],r[i][1]=j;

					if(dpM[i][2]<(-1ll*i*dish[i][j]+1ll*(i+1)*dish[i][k]))
						dpM[i][2]=-1ll*i*dish[i][j]+1ll*(i+1)*dish[i][k],r[i][2]=j;

					if(dpM[i][3]<(-1ll*i*dish[i][j]-1ll*(i+1)*dish[i][k]))
						dpM[i][3]=-1ll*i*dish[i][j]-1ll*(i+1)*dish[i][k],r[i][3]=j;
				}
			}

			x=10000000,y=-1;
			for(int i=0;i<a[n-1];i++){
				if(x>dish[n-1][i])	x=dish[n-1][i],r[n-1][0]=i;
				if(y<dish[n-1][i])	y=dish[n-1][i],r[n-1][1]=i;
			}
			r[n-1][2]=r[n-1][0],r[n-1][3]=r[n-1][1];

			x=10000000,y=-1;
			for(int i=0;i<a[0];i++){
				if(x>dish[0][i])	x=dish[0][i],r[0][0]=(i+1)%a[0];
				if(y<dish[0][i])	y=dish[0][i],r[0][1]=(i+1)%a[0];
			}
			r[0][2]=r[0][0],r[0][3]=r[0][1];

			dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=0;
			for(int i=1;i<n;i++){
				for(int j=0;j<4;j++){
					dp[i][j]=0;
					for(int k=0;k<4;k++){
						x=(r[i-1][k]+a[i-1]-1)%a[i-1];
						dp[i][j]=maX(dp[i][j],dp[i-1][k]+1ll*i*abs(dish[i-1][x]-dish[i][r[i][j]]));
					}
				}
			}
			sum=0;
			for(int i=0;i<4;i++)
				sum=maX(sum,dp[n-1][i]);
			
			printf("%lld\n",sum);
		}
		for(int i=0;i<n;i++)
			dish[i].clear();
	}
	return 0;
}
