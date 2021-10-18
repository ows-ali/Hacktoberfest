#include <bits/stdc++.h>
using namespace std;

int eggdrop(int n, int k){
    int eggfloor[n+1][k+1], res;
    for(int i=1; i<=n; i++){
        eggfloor[i][0] = 0;
        eggfloor[i][1] = 1;
    }
    
    for(int i=1; i<=k; i++)
        eggfloor[1][i] = i;
        
    for(int i=2; i<=n; i++){
        for(int j=2; j<=k; j++){
            eggfloor[i][j] = INT_MAX;
            for(int x=1; x<=j; x++){
                res = 1 + max(eggfloor[i-1][x-1], 
                        eggfloor[i][j-x]);
                if(res < eggfloor[i][j])
                    eggfloor[i][j] = res;
            }
        }
    }
    return eggfloor[n][k];
}

int main() {
	int T, n, k;
	cin>>T;
	while(T--){
	    cin>>n>>k;
	    cout<<eggdrop(n, k)<<endl;
	}
	return 0;
}
