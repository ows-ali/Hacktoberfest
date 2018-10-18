#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t-- > 0) {
    long n, k;
    cin >> n >> k;

    if (k == 0)
      cout << "0 " << n << endl;
    else
      cout << n / k << " " << n % k << endl;
  }
  return 0;
}
