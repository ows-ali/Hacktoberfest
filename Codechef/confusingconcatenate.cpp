#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> c(n);
    bool flag = false;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> c[i];
    }
    for (int i = 1; i < n; i++)
    {
      if (c[i] > c[0])
      {
        flag = true;
        index = i;
        break;
      }
    }

    if (flag == false)
    {
      cout << -1 << endl;
      return 0;
    }
    cout << index << endl;
    for (int i = 0; i < index; i++)
    {
      cout << c[i] << " ";
    }
    cout << endl;
    cout << n - index << endl;
    for (int i = index; i < n; i++)
    {
      cout << c[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
