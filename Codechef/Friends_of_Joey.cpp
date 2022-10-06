/*=============================================================================
#  Author:          saurabhcodes25
#  Problem Link:    https://www.codechef.com/DSA22022/problems/FRIENDSJOEY
=============================================================================*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl "\n"
#define MOD 1e9 + 7
int factorial(int x)
{
    if (x <= 1)
        return 1;
    int res = 2;
    for (int i = 3; i <= x; i++)
        res = res * i;
    return res;
}
 
int gcdOfFactorial(int m, int n)
{
    return factorial(min(m, n));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    cin >> a >> b;
    cout << gcdOfFactorial(a, b) << endl;
}