//https://leetcode.com/problems/pascals-triangle/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for(int i=0;i<numRows;++i)
        {
            vector<int> temp;
            for(int j=0;j<=i;++j){
                if(i==j || j==0){
                temp.push_back(1);
                }
                else{
                    temp.push_back(pascal[i-1][j-1]+pascal[i-1][j]);
                 }
            }
            pascal.push_back(temp);
        }
        return pascal;
    }
};