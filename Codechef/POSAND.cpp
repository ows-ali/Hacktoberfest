#include <bits/stdc++.h>
using namespace std;
#define ll int
bool isPowerOfTwo(ll n)
{
    return n!=0 && ((n&(n-1))==0);
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        set<ll> p;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        else if (isPowerOfTwo(n))
        {
            cout << -1 << endl;
        }
        else
        {
            cout << 2 << " " << 3 << " " << 1;
            p.insert(2);
            p.insert(3);
            p.insert(1);
            for (ll i = 4; i <= n; i++)
            {
                if (isPowerOfTwo(i))
                {
                    cout << " " << i + 1 << " " << i;
                    p.insert(i + 1);
                    p.insert(i);
                }
                else
                {
                    if (p.find(i) != p.end())
                    {
                        continue;
                    }
                    else
                    {
                        cout << " " << i;
                    }
                }
            }
            cout << endl;
        }
    }
}
