#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define nline '\n'

void solve() {
	int n; cin >> n;
	if (n >= 7) cout << "YES" << nline;
	else if (n % 2 == 0) cout << "YES" << nline;
	else cout << "NO" << nline;

}
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}
