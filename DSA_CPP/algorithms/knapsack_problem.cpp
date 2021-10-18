#include <iostream>
#define MAX 101
using namespace std;

int max(int a, int b) {
	return (a > b) ? (a) : (b);
}

int main() {
	int W = 50;
	int N = 3;
	int w[3] = { 10,20,30 };
	int v[3] = { 60,100,120 };
	int b[MAX][MAX];

	for (int j = 0; j <= W; j++) {
		b[0][j] = 0;
	}

	for (int i = 0; i <= N; i++) {
		b[i][0] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= W; j++) {
			if (j - w[i - 1] < 0) {
				b[i][j] = b[i - 1][j];
			}
			else {
				b[i][j] = max(b[i - 1][j], b[i - 1][j - w[i - 1]] + v[i - 1]);
			}
		}
	}

	int i = N;
	int k = W;

	cout << "Select:" << endl;
	while (i > 0) {
		if (b[i][k] != b[i - 1][k]) {
			cout << v[i - 1] << " " << w[i - 1] << endl;
			k -= w[i - 1];
		}
		i--;
	}

	cout << "Total Sum: " << b[N][W] << endl;
}