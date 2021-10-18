// Time complexity of update and read operations: O(logn)

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
int fenwick[MAXN], n;

void update(int index, int val) {
	while(index <= n) {
		fenwick[index] += val;
		index += index & (-index);
	}
}

int read(int index) {
	int sum = 0;

	while(index > 0) {
		sum += fenwick[index];
		index -= index & (-index);
	}

	return sum;
}