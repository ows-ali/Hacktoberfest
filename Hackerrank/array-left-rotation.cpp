#include <iostream>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int j = k; j < n; j++)
    cout << arr[j] << " ";

  for (int p = 0; p < k; p++)
    cout << arr[p] << " ";

  return 0;
}
