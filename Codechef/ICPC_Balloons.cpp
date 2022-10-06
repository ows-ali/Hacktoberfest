/*=============================================================================
#  Author:          saurabhcodes25
#  Problem Link:    https://www.codechef.com/COOK130C/problems/BALLOON
=============================================================================*/
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef int long long ll;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int count = 0;
        int count2 = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] <= 7)
            {
                count++;
            }
            if (count == 7)
            {
                count2 = i + 1;
                count++;
            }
        }
        cout << count2 << endl;
    }

    return 0;
}