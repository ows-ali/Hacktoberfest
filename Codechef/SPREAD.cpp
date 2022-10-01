//  Aman Agrawal
//  Github handle: amanagr6697
//  Problem Name: SPREAD
//  Platform: Codechef
//  URL: https://www.codechef.com/problems/SPREAD
//  Standard C++ file, easily execuatable on any ide supporting C++ version 11 or above

#include <bits/stdc++.h>
#define int long long
using namespace std;
#define full(v1) v1.begin(), v1.end()
#define pb push_back
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define endl "\n"
#define is(x) cerr << #x << " is " << x << "\n";
// Maintaining 2 fenwick trees to handle both operations effectively
int fenwick1[1000009];
int fenwick2[1000009];
int n;
// Query functions to find the value of given index
int query1(int x)
{
  int sum = 0;
  while (x)
  {
    sum += fenwick1[x];
    x -= (x & (-x));
  }
  return sum;
}
int query2(int x)
{
  int sum = 0;
  while (x)
  {
    sum += fenwick2[x];
    x -= (x & (-x));
  }
  return sum;
}
// Updating fenwicks accordingly to the value and index
void update1(int x, int val)
{
  while (x <= n)
  {
    fenwick1[x] += val;
    x += (x & (-x));
  }
}
void update2(int x, int val)
{
  while (x <= n)
  {
    fenwick2[x] += val;
    x += (x & (-x));
  }
}
void solve()
{
  int i, j, t, q, a, b, m, k, ct = 0, sum = 0, flag = 0;
  //  Problem of range update with point query using 2 fenwick trees
  //  Concept of difference sum is being appplied here
  cin >> n >> q >> k;
  for (int i = 1; i <= n; i++)
  {
    update1(i, k);
    update1(i + 1, -k);
  }
  while (q--)
  {
    char c;
    cin >> c;
    if (c == 'S')
    {
      cin >> a >> b >> k;
      update1(a, k);
      update1(b + 1, -k);
      update2(a, k * (a - 1));
      update2(b + 1, -k * b);
    }
    else
    {
      cin >> a;
      b = a;
      a--;
      cout << query1(b) * b - query2(b) - (query1(a) * a - query2(a)) << endl;
    }
  }
}
signed main()
{
  // For fast input/output
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--)
  {
    solve();
    cout << "\n";
  }
  //  Tells total time taken to run the code according to the input given
  cerr << clock() * 1000.0 / CLOCKS_PER_SEC << 'm' << 's';
  return 0;
}
