/*problem link:-https://www.codechef.com/problems/COVID19B*/

//covid19b
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void rec(vector<vector<double>> a, set<ll> &s, ll p, ll n, double t)
{
    ll i;
    for (i = 0; i < n; i++)
    {
        if (a[p][i] > t)
        {
            s.insert(i);
            rec(a, s, i, n, a[p][i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, j, k, t, ip;
    cin >> t;
    while (t--)
    {
        ll n, pi, b, c, d, x, y, z, q, r, m, pj;
        double d1, d2;
        // string s;
        vector<ll> v, ba, sa;
        set<ll> s;
        cin >> n;
        ll ar[n];
        vector<vector<double>> a(n, vector<double>(n, 0));
        for (i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (ar[i] == ar[j])
                {
                    a[i][j] == -1;
                }
                else
                {
                    d1 = (i - j) / float(ar[j] - ar[i]);
                    if (d1 <= 0)
                    {
                        a[i][j] = -1;
                    }
                    else
                    {
                        a[i][j] = d1;
                    }
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            //cout << "x";
            s.insert(i);
            rec(a, s, i, n, 0);
            v.push_back(s.size());
            s.clear();
        }

        cout << *min_element(v.begin(), v.end()) << " " << *max_element(v.begin(), v.end()) << "\n";
    }
    return 0;
}
