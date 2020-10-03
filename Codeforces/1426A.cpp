/* I solved problem 1426A from Codeforces, named Floor Number.
Link to it : https://codeforces.com/contest/1426/problem/A
Check submission https://codeforces.com/contest/1426/submission/94553749 
*/

#include <iostream>

void solve()
{
    int n;
    int x;
    std::cin >> n >> x;
    if(n <= 2) std::cout << 1 << '\n';
    else if((n - 2) % x != 0)
    {
        std::cout << (n - 2) / x + 2 << '\n';
    }
    else
    {
        std::cout << (n - 2) / x + 1 << '\n';
    }
}

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        solve();
    }
}