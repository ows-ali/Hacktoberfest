#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool exponentOfTwo = ( n & (n-1) == 0);
	cout << ( exponentOfTwo ? "YES" : "NO" ) << endl;
}