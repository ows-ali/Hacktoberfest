//https://leetcode.com/problems/longest-consecutive-sequence/submissions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size(); // extract the size of array
        if(n == 0) return 0; // if length of array is zero, then from here simply return 0
        
        sort(arr.begin(), arr.end()); // sort the array
        
        int mxLen = 0, currLen = 1; // put mxLen = 0, and currLen as 1
        
        for(int i = 1; i < n; i++) // traverse from the array
        {
            if(arr[i] == arr[i - 1] + 1) // this is the part of consecutive sequence
            {
                currLen++; // increase the curr Length by 1
            }
            else if(arr[i] != arr[i - 1]) // but if it is not equal
            {
                mxLen = max(mxLen, currLen); // update our mxLen 
                currLen = 1; // and reset the currLen with 1
            }
        }
        
        mxLen = max(mxLen, currLen); // update our mxLen 
        return mxLen; // Finally return mxLen
    }
};