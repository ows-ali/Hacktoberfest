/* I solved problem 1426B from Codeforces, named Floor Number.
Link to it : https://codeforces.com/contest/1426/problem/B
Check submission https://codeforces.com/contest/1426/submission/94555169 
*/

#include <iostream>

void solve()
{
    int n, m;
    std::cin >> n >> m;
    int arr[4 * n];
    int j = 0;
    for(int i = 0; i < 2 * n; i++)
    {
        std::cin >> arr[j] >> arr[j + 1];
        j += 2;
    }
    if(m % 2 != 0)
    {
        std::cout << "NO\n";
        return;
    }
    if(n == 1)
    {
        if(arr[1] == arr[2]) 
        {
            std::cout << "YES\n";
        }
        else
            std::cout << "NO\n";
    }
    else 
    {
        for(int i = 0; i < 4 * n - 1; i += 4)
        {
            if(arr[i + 1] == arr[i + 2]){
                std::cout << "YES\n";
                return;
            }
        }
        std::cout << "NO\n";
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