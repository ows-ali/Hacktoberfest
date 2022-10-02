// Made By Elstuhn
// https://codeforces.com/problemset/problem/1661/A
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  int n;
  int num;
  int ans;
  cin >> t;
  for (int i = 0; i < t; i++) {
    ans = 0;
    cin >> n;
    int a[n];
    int b[n];
    for (int j = 0; j < n; j++) {
      cin >> num;
      a[j] = num;
    }
    
    for (int j = 0; j < n; j++) {
      cin >> num;
      b[j] = num;
    }
    
    for (int j = 0; j < n-1; j++) {
      ans += min((abs(a[j+1]-a[j]) + abs(b[j+1]-b[j])), (abs(b[j+1]-a[j]) + abs(a[j+1]-b[j])));
    }
    cout << ans << "\n";
  }
  return ans;
}