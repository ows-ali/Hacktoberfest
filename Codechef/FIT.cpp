#include <iostream>
using namespace std;

/*
    First input is to determine number of tests to be done.
    Following inputs should be distances to be tested.
*/

// Const variable depending on how many days Chef goes
// to work.
const int days = 5;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t ; i++)
    {
        {
            float x; // Distance from office to home.
            cin >> x;
            cout << (days * x * 2) << endl;
        }
    }
	return 0;
}

