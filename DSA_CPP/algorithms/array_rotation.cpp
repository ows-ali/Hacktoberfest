// Rotate an array of size n by d elements.
// Time Complexity: O(n).

#include<bits/stdc++.h>
using namespace std;

void rotate(int [], int, int);
int gcd(int, int);

int main() {
  int n, d;
  cout<<"Enter the size of the array: ";
  cin>>n;
  int a[n];

  for(int i = 0; i < n; i++) {
      cout<<"Enter the elements into the array: ";
      cin>>a[i];
  }
  cout<<"Enter the value of d: ";
  cin>>d;

  rotate(a, n, d);
  cout<<"Rotated array: ";
  for(int i = 0; i < n; i++) {
    cout<<a[i]<<" ";
  }
  return 0;
}

void rotate(int a[], int n, int d) {
  for(int i = 0; i < gcd(n, d); i++) {
    int temp = a[i];
    int j = i;

    // The below loop is used to shift the elements to their respective positions.
    while(1) {
      int k = j + d; // takes care if the k value goes out of index.
      if(k >= n) {
        k = k - n;
      }

      if(k == i) {
        break;
      }

      a[j] = a[k];
      j = k;
    }
    a[j] = temp;
  }
}

int gcd(int a, int b) {
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
