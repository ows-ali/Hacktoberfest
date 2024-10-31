#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n;
        cin >> n; // Number of elements in the array
        unordered_map<int, int> freqMap; // To store frequency of each element

        // Reading elements and updating frequency map
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ++freqMap[a];
        }

        // Collect frequencies into a vector
        vector<int> frequencies;
        for (auto i : freqMap) {
            frequencies.push_back(i.second);
        }

        // Sort frequencies in ascending order
        sort(frequencies.begin(), frequencies.end());

        int maxValue = 1;
        int sumFrequencies = 0;
        int count = 1;

        // Calculate the maximum value based on frequencies
        for (int i = frequencies.size() - 1; i >= 0; --i) {
            sumFrequencies += frequencies[i];
            maxValue = max(maxValue, (sumFrequencies / count) * count);
            ++count;
        }

        cout << maxValue << endl; // Output the result for this test case
    }
    return 0;
}

/*
Example 1:
Input:
1
6
1 2 2 3 4 4

Explanation:
- The input has one test case with 6 elements: [1, 2, 2, 3, 4, 4]
- The frequencies of each element are: {1:1, 2:2, 3:1, 4:2}
- Sorted frequencies: [1, 1, 2, 2]
- Calculations:
  - When count=1, sumFrequencies=2 -> maxValue = 2
  - When count=2, sumFrequencies=4 -> maxValue = 4
  - Result for this test case = 4

Output:
4

Example 2:
Input:
1
8
1 1 2 2 3 3 4 4

Explanation:
- The input has one test case with 8 elements: [1, 1, 2, 2, 3, 3, 4, 4]
- The frequencies of each element are: {1:2, 2:2, 3:2, 4:2}
- Sorted frequencies: [2, 2, 2, 2]
- Calculations:
  - When count=1, sumFrequencies=2 -> maxValue = 2
  - When count=2, sumFrequencies=4 -> maxValue = 4
  - When count=3, sumFrequencies=6 -> maxValue = 6
  - When count=4, sumFrequencies=8 -> maxValue = 8
  - Result for this test case = 8

Output:
8

Example 3:
Input:
1
5
5 5 5 6 6

Explanation:
- The input has one test case with 5 elements: [5, 5, 5, 6, 6]
- The frequencies of each element are: {5:3, 6:2}
- Sorted frequencies: [2, 3]
- Calculations:
  - When count=1, sumFrequencies=3 -> maxValue = 3
  - When count=2, sumFrequencies=5 -> maxValue = 4 (5 // 2 * 2)
  - Result for this test case = 4

Output:
4
*/
