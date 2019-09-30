//https://www.codechef.com/problems/FLOW005

#include <iostream>
using namespace std;
int a[6] = {1, 2, 5, 10, 50, 100};
long long int count(long long int n)
{
    long long int count = 0;
    for (int i = 5; i > 0; i--)
    {
        count += n / a[i];
        n %= a[i];
    }
    count += n;
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        cout << count(n) << endl;
    }
    return 0;
}
