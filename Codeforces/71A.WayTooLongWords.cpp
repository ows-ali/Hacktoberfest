#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        string result = "";
        cin >> s;
        int length = s.size();
        if (length > 10)
        {
            result = result + s[0] + to_string(length - 2) + s[length - 1];
        }
        else
        {
            result = s;
        }
        cout << result << endl;
    }
    return 0;
}