/*=============================================================================
#  Author:          saurabhcodes25
#  Problem Link:    https://www.codechef.com/START23C/problems/SUBMEX
=============================================================================*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl "\n"
#define MOD 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int n, k, x;cin >> n >> k >> x;
        int cnt = 0;
        if (x > k)cout << -1 << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (cnt == x)cnt = 0;
                cout << cnt << " ";
                cnt++;
            }
            cout << endl;
        }
    }

    return 0;
}