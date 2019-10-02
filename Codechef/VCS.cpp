//https://www.codechef.com/problems/VCS

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int ignore[m], track[k], i, x = 0, y = 0;
        int a[n + 1] = {0};
        for (i = 0; i < m; i++)
        {
            cin >> ignore[i];
            a[ignore[i]]++;
        }
        for (i = 0; i < k; i++)
        {
            cin >> track[i];
            a[track[i]]++;
        }
        for (i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                y++;
            }
            else if (a[i] == 2)
            {
                x++;
            }
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
