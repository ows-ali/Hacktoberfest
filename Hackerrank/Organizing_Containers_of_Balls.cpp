/*
    https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

string organizingContainers(vector<vector<ll> > &M) {

    int n = M.size();

    if (n == 1)
        return "Possible";

    unordered_map<ll, ll> ump;

    for (int i = 0; i < n; ++i) {
        ll containerSum = 0;
        for (int j = 0; j < n; ++j) {
            containerSum += M[i][j];
        }
        ++ump[containerSum];
    }

    for (int i = 0; i < n; ++i) {
        ll typeSum = 0;
        for (int j = 0; j < n; ++j) {
            typeSum += M[j][i];
        }
        if (ump[typeSum] == 0)
            return "Impossible";
        else
            --ump[typeSum];
    }

    return "Possible";
}


int main() {

    int q;
    cin >> q;

    while (q--) {

        int n;
        cin >> n;

        vector<vector<ll> > M(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ll count;
                cin >> count;
                M[i].emplace_back(count);
            }
        }

        string res = organizingContainers(M);
        cout << res << '\n';
    }

    return 0;
}