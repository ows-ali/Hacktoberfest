#include<iostream>
#include <vector>

using namespace std;

// The below function will solve the Hackerrank problem found at https://www.hackerrank.com/challenges/diagonal-difference/problem
int diagonalDifference(vector<vector<int>> arr) {

	size_t length{ arr.size() };
	int primarySum{};
	int secondarySum{};

	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (i == j)
			{
				primarySum += arr[i][j];
				cout << "Adding to primary sum at position (" << i << "," << j << ") = " << arr[i][j];
			}

			if (j == (length - 1) - i) {
				secondarySum += arr[i][j];
				cout << "Adding to secondary sum at position (" << i << "," << j
					<< ") = " << arr[i][j];
			}
		}
	}

	return abs(primarySum - secondarySum);
}

int main()
{
	return 0;
}