//https://leetcode.com/problems/k-inverse-pairs-array/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = { 1 };
        
        for(int i=1;i<=n;++i)
            for(int K=0; K<=k;++K)
                for(int j=0; j<= min(K,i-1);++j)
                    dp[i][K] = (dp[i][K] + dp[i-1][K-j])%1000000007;
        return dp[n][k];
    }
};