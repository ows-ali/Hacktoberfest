#include <bits/stdc++.h>

using namespace std;

void readInt(int &n) {
	static char c;
	while ((c = getchar_unlocked()) && c <= ' ');
	n = c - '0';

	while ((c = getchar_unlocked()) && c > ' ') n = (n << 3) + (n << 1) + c - '0';
}

int main() {
	int n, k;
	readInt(n); readInt(k);

	int ans = 0;
	while (n--) {
		int foo; readInt(foo);
		ans += foo % k == 0;
	}

	printf("%d\n", ans);
	return 0;
}