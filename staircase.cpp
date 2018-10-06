#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void staircase(int n) {
    for (int i = 0; i < n; i++)
    {
        int j = n;
        while (j > i + 1)
        {
            cout << ' ';
            j--;
        }
        int k = 0;
        while (k <= i)
        {
            cout << '#';
            k++;
        }
        cout << '\n';
    }

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
