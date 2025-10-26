#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (true)
    {
        string s;
        cin >> s;
        if (s == "00e0")
            break;

        int n = stod(s);
        int a = floor(log2(n));
        int l = n - pow(2, a);
        int result = 2 * l + 1;

        cout << result << endl;
    }
}