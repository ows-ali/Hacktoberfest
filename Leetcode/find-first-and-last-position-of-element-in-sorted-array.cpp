//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size=nums.size();
        vector<int> a;
        int index;
        int count=0;
        for(int i=0;i<size;i++)
        {
            if(nums[i]==target)
            {
                index=i;
                count++;
            }
        }
        if(count==0)
        {
            a.push_back(-1);
            a.push_back(-1);
            return a;
        }
        else if(count>1)
        {   
            a.push_back(index-count+1);
            a.push_back(index);
                return a;
        }
        else
        {
            a.push_back(index);
            a.push_back(index);
            return a;
        }
    }
};