//https://leetcode.com/problems/interleaving-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(string& s1, string& s2, string &s3, int l1, int l2, int l3, vector<vector<int>>&dp) {
        if(l1<0 && l2<0 && l3<0) {
            return true;
        }
        if(l1>=0 && l2>=0 && dp[l1][l2]!=-1) {
            return dp[l1][l2];
        }
        if(l1>=0 && s1[l1]==s3[l3] && l2>=0 && s2[l2]==s3[l3] ) {
            return dp[l1][l2] = (helper(s1, s2, s3, l1-1, l2, l3-1, dp) || helper(s1, s2, s3, l1, l2-1, l3-1, dp));
        }
        else if(l1>=0 && s1[l1]==s3[l3])
            return helper(s1, s2, s3, l1-1, l2, l3-1, dp);
        
        else if(l2>=0 &&s2[l2]==s3[l3])
            return helper(s1, s2, s3, l1, l2-1, l3-1, dp);
        
        else return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
			return false;
        vector<vector<int>>dp(s1.size()+1, (vector<int>(s2.size()+1, -1)));
        // memset(dp, -1, sizeof(dp));
        return helper(s1, s2, s3,s1.size()-1, s2.size()-1, s3.size()-1, dp);
    }
};