nclude <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, m, k;
        cin >> n >> m >> k;
        if (__gcd(n, k) > 1 || __gcd(m, k) > 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << m * n << endl;
        }
    }
    return 0;
}
