#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPerfectSquare(int n)
{
    if (n < 2)
        return true;
    int s = 1, e = n / 2;
    ll m;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (m * m == n)
        {
            return true;
        }
        else if (m * m > n)
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    cout<<isPerfectSquare(n);

    return 0;
}