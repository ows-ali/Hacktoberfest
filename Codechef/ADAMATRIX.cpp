#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        int count = 0;
        for (int l = n - 1; l >= 0; l--)
        {
            for (int i = 0; i <= l; i++)
            {
                if (arr[i][l] > arr[l][i])
                {
                    for (int m = 0; m < l + 1; m++)
                    {
                        for (int k = m + 1; k < l + 1; k++)
                        {
                            swap(arr[m][k], arr[k][m]);
                        }
                    }
                    count++;
                    break;
                }
            }
        }
        cout << count << endl;
    }
}
