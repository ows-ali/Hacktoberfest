// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        sort(nums.begin(), nums.end());
        int mid = n / 2;
        for (int i = 0; i < n; i++)
        {
            sum += abs(nums[mid] - nums[i]);
        }
        return sum;
    }
};