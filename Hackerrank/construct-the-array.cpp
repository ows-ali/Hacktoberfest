#include <bits/stdc++.h>
using namespace std;


long long int countArray(long int n, long int k, long int x) {

    long long int dp[n][2];

    dp[0][0] = 1;
    dp[0][1] = 0;

    for(long int i = 1; i < n; i++) {
        dp[i][0] = (dp[i - 1][1] * (k - 1)) % 1000000007;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * (k - 2)) % 1000000007;
    }
    return (x == 1 ? dp[n - 1][0] : dp[n - 1][1]) % 1000000007;
}

int main() {
    long int n, k, x;
    cin >> n >> k >> x;
    cout << countArray(n, k, x);
    return 0;
}