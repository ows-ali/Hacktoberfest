/*
    https://www.hackerrank.com/challenges/service-lane/problem
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, t;
    cin >> n >> t;

    int width[n];
    for (int i = 0; i < n; ++i) {
        cin >> width[i];
    }

    while (t--) {

        int start, end;
        cin >> start >> end;

        int minSize = INT_MAX;

        for (int i = start; i <= end; ++i) {
            minSize = min(minSize, width[i]);
        }

        cout << minSize << '\n';
    }

    return 0;
}
