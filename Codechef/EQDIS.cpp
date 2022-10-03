// Equal Distinct PROBLEM ON CODECHEF

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
typedef long long int ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        int arr[a];
        for (int i = 0; i < a; i++)
        {

            cin >> arr[i];
        }

        unordered_map<int, int> mp;
        for (int i = 0; i < a; i++)
        {

            mp[arr[i]]++;
        }
        int count = 0;
        for (auto x : mp)
        {

            if (x.second > 1)
            {

                count += x.second;
            }
        }

        int res = a - count;

        if ((count == 0) && (a % 2 != 0))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}