
//C++ code for the Sparse array question on hackerrank
#include <iostream>
#include <string>

using namespace std;

const int N = int(1e3) + 100;

string x[N];
int cnt[N], sz = 0;

void add(string s) {
  for (int i = 0; i < sz; i++) {
    if (x[i] == s) {
      cnt[i] += 1;
      return;
    }
  }
  cnt[sz] = 1;
  x[sz++] = s;
}

int query(string s) {
  for (int i = 0; i < sz; i++) {
    if (x[i] == s) {
      return cnt[i];
    }
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    add(s);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    string s;
    cin >> s;
    cout << query(s) << '\n';
  }
  return 0;
}