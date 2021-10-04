#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int  main()
{
	int t;
	cin >> t;
	while (t--) {
		ll n = 10, a = 0, b = 0;
		ll arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (i % 2 == 0) a += arr[i];
			else b += arr[i];
		}
		if (a == b) cout << 0;
		if (a > b) cout << 1;
		if (b > a) cout << 2;
		cout << endl;
	}
}