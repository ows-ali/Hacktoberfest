#include <iostream>
#include <map>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second > b.second;
}

void fun(int arr[], int n) {
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    m[arr[i]]++;
  }

  // print the map
  map<int, int>::iterator it;
  // for (it = m.begin(); it != m.end(); it++) {
  //   cout << "\t" << it->first << "\t" << it->second << endl;
  // }

  // make a pair array.
  pair<int, int> p[m.size()];
  it = m.begin();
  for (int i = 0; i < m.size(); i++) {
    p[i] = make_pair(it->first, it->second);
    it++;
  }

  // sort the array.
  sort(p, p + m.size(), compare);

  // print the pair array.
  for (int i = 0; i < m.size(); i++) {
    cout << (p[i]).first << " " << (p[i]).second << endl;
  }
}

int main() {
  int arr[] = {1, 2, 1, 2, 4, 2, 5, 6, 4, 3, 2, 1, 2, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  fun(arr, n);
}
