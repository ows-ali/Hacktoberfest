#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);

  while (t-- > 0) {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];

      totalSum += arr[i];
    }

    sort(arr, arr + n);

    if (k > n / 2)
      k = n - k;
    int sumSon = 0, sumFather = 0;
    for (int i = 0; i < k; i++)
      sumSon += arr[i];

    sumFather = totalSum - sumSon;

    int diff = sumFather - sumSon;

    printf("%d\n", diff);
  }

  return 0;
}
