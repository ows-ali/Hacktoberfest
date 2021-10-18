// No performance gain.
// Worst Case Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

void rotate(int [], int, int);
void reverse(int [], int, int);

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
  reverse(a,0,d-1);
  reverse(a,d,n-1);
  reverse(a,0,n-1);
}

void reverse(int a[], int start, int end) {
  while(start < end) {
    swap(a[start], a[end]);
    start++;
    end--;
  }
}
