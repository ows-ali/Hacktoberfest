#include<bits/stdc++.h>
using namespace std;

long long fast_expo(long long x, long long y, long long mod) {
    long long res = 1;
    x %= mod;
    while(y) {
        if(y % 2) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

int main() {

    long long x, y, mod;
    cin >> x >> y >> mod;

    cout << fast_expo(x, y, mod) << "\n";

    return 0;
}