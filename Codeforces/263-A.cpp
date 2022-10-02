#include <iostream>
using namespace std;

int main()
{
    int x = 0, i = 0, ctr = 0, flag = 0;
    while (true)
    {
        cin >> x;
        if (x == 1)
        {
            flag = 1;
            ctr++;
        }
        if (!flag)
            ctr++;
        i++;
        if (i == 25)
            break;
    }
    int r;
    r = ctr / 5;
    if (ctr % 5 != 0)
        r++;
    int c = ctr % 5;
    if (c == 0)
        c = 5;
    int steps = 0;
    steps = ((r - 3 > 0) ? (r - 3) : (3 - r)) + ((c - 3 > 0) ? (c - 3) : (3 - c));
    cout << steps;

    return 0;
}