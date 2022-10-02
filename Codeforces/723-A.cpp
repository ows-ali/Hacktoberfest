#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    a--,b--,c--;
    int len = max(a, max(b, c));
    int arr[len];
    int i;
    for (i = 0; i < len; i++)
    {
        arr[i] = (((c - i) >= 0) ? (c - i) : (i - c)) + (((b - i) >= 0) ? (b - i)
                                     : (i - b)) + (((a - i) >= 0)   ? (a - i)
                                                               : (i - a));
        //cout<<arr[i]<<endl;
    }
    sort(arr, arr + len);
    cout << arr[0] << endl;
    return 0;
}