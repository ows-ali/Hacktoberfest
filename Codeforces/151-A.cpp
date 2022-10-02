#include <iostream>
using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int lime = c * d / n;
    int drinks = k * l;
    int n1 = drinks / (nl * n), n2 = p / (np * n);
    int res = (n1 > n2 && lime > n2) ? n2 : ((n1 > lime) ? lime : n1);
    cout << res << endl;

    return 0;
}