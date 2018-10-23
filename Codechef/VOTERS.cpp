#include <cstdio>
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main() {
	map <int, int> m;

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int temp;
	for (int i = 0; i < a + b + c; i++) {
		scanf("%d", &temp);
		m.insert(pair<int, int>(temp, m[temp]++));
	}

	map <int, int> :: iterator itr;
	int counter = 0;
	for (itr = m.begin(); itr != m.end(); ++itr) {
		if (itr->second >= 2)
			counter++;
	}

	printf("%d\n", counter);
	for (itr = m.begin(); itr != m.end(); ++itr) {
		if (itr->second >= 2)
			printf("%d\n", itr->first);
	}

	return 0;
}
