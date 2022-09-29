// Problem Name - Chef and GCD
// Problem Link - https://www.codechef.com/COOK131C/problems/CHFGCD

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int x, y;
        cin >> x >> y;

        if (__gcd(x, y) > 1)
        {
            cout << "0\n";
        }
        else if (__gcd(x + 1, y) > 1 || __gcd(x, y + 1) > 1)
        {
            cout << "1\n";
        }
        else
        {
            cout << "2\n";
        }
    }

    return 0;
}