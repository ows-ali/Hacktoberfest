//https://leetcode.com/problems/wiggle-subsequence/submissions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int countp=1,countn=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1]) countp=countn+1;
            else if(nums[i]<nums[i-1]) countn=countp+1;
        }
        return max(countp,countn);
    }
};