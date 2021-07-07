#include <stdio.h>
const int M = 1000000007;
int main() {
  int t;
  int n, a, i;
  long int arr[50001]={0};
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d", &a);
      arr[a]++;
    }

     long  sum = 0;
     long  product = 1;
    for (i = 0; i < n; i++) {
      sum = (sum +arr[i] )%M;
      product =( (product) * (sum ))%M;
      sum=(sum-1)%M;
      arr[i] = 0; // reset the array
    }
    arr[i] = 0; // reset for next test case
    printf("%lld\n", product%M );
  }
  return 0;
}
