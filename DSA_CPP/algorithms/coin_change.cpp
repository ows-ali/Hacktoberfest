#include <bits/stdc++.h>
using namespace std;

int change(int a[], int m, int n){
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=0; i<m; i++){
        for(int j=a[i]; j<=n; j++)
            dp[j] += dp[j-a[i]];
    }
    return dp[n];
}

int main() {
	int T, m, n, a[300];
	cin>>T;
	while(T--){
	    cin>>m;
	    for(int i=0; i<m; i++) cin>>a[i];
	    cin>>n;
	    cout<<change(a, m, n)<<endl;
	}
	return 0;
}
