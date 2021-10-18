// An sorted array is rotated by d.
// We need to find an element.

// Worst Case Time Complexity = O(log n).

#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[], int low, int high, int x) {
  if(low <= high) {
      int mid = low + (high - low)/2;
      if(a[mid] == x) {
        return mid;
      }

      if(a[mid] < x) {
        return binary_search(a, mid + 1, high, x);
      }
      else {
        return binary_search(a, low, mid - 1, x);
      }
  }
  return -1;
}

int findPivot(int a[], int low, int high) {
  if(high < low) return -1;
  if(high == low) return low;

  int mid = (low + high)/2;

  if(mid < high && a[mid] > a[mid+1]) {
    return mid;
  } else if(mid > low && a[mid] < a[mid-1]) {
    return mid-1;
  }

  if(a[low] >= a[mid]) {
    return findPivot(a, low, mid - 1);
  }
  return findPivot(a, mid + 1, high);
}

int pivotedBinarySearch(int a[], int n, int x) {
  int pivot = findPivot(a, 0, n - 1);

  if(pivot == -1) {
    return binary_search(a, 0, n-1, x);
  }

  if(a[pivot] == x) return pivot;
  else if(a[0] <= x) return binary_search(a, 0, pivot - 1, x);

  return binary_search(a, pivot + 1, n - 1, x);
}

int main() {
  cout<<"Enter size of the array: ";
  int n;
  cin>>n;
  int a[n];

  cout<<"Enter sorted and rotated array!"<<endl;

  for(int i = 0; i < n; i++) {
    cout<<"Enter element into the array: ";
    cin>>a[i];
  }

  int x;
  cout<<"Enter element to search: ";
  cin>>x;
  cout<<pivotedBinarySearch(a, n, x);
  return 0;
}
