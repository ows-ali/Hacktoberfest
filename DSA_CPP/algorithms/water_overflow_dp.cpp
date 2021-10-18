#include<bits/stdc++.h>
using namespace std;
double solve(double k,int r,int c){
  
  if(c>r)
    return 0;
    
  double *glass=new double[r*(r+1)/2];
  memset(glass, 0, sizeof(glass));
  int idx=0;
  glass[0] = k;
  for(int i=1;i<=r;i++){
      for(int j=1;j<=i;j++,idx++){
          k = glass[idx];
          glass[idx] = (k>=1.0)?1.0f:k;
          k = (k>=1.0)?(k-1):0.0f;
          glass[i+idx]+=k/2;
          glass[i+idx+1]+=k/2;
          
      }
  }
   return glass[r*(r-1)/2+c-1]; 
}

int main()
{
	int t;
	cin>>t;
	while(t-->0){
	   int k,r,c;
	   cin>>k>>r>>c;
	   double ans = solve(k*1.0,r,c);
	   cout<<fixed<<setprecision(6)<<ans<<"\n";
    
  }
}
