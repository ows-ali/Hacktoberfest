#include <iostream>
using namespace std;

const int HOUSES = 100;

int numOfSafeHouses(int m, int x, int y, bool isSafe[HOUSES], int police_houses[]) {
    int num_of_houses_covered = x * y;
    for (int i = 0; i < m; i++) {
        for (int j = police_houses[i] - 1; j >= max(police_houses[i] - num_of_houses_covered, 0); j--) {
            isSafe[j] = false;
        }
        for (int j = police_houses[i] + 1; j <= min(police_houses[i] + num_of_houses_covered, HOUSES - 1); j++) {
            isSafe[j] = false;
        }
    }
    int safeHouses = 0;
    for (int i = 0; i < HOUSES; i++) {
        if (isSafe[i]) {
            safeHouses++;
        }
    }
    return safeHouses;
}

int main() {
	int t;
	cin >> t;
	int m, x, y;
    bool isSafe[HOUSES];
	while (t--) {
	    for (int i = 0; i < HOUSES; i++) {
	        isSafe[i] = true;
	    }
	    cin >> m >> x >> y;
	    int police_houses[m];
	    for (int i = 0; i < m; i++) {
	        cin >> police_houses[i];
	        police_houses[i]--;
	        isSafe[police_houses[i]] = false;
	    }
	    cout << numOfSafeHouses(m, x, y, isSafe, police_houses) << "\n";
	}
	return 0;
}
