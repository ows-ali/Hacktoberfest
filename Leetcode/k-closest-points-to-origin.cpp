//https://leetcode.com/problems/k-closest-points-to-origin/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector <vector<long int>> distances;
        vector <vector<int>> ans;
        
        for (int i=0; i<points.size(); i++){
            long int d = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            
            vector<long int> temp; temp.push_back(d); temp.push_back(i);
            distances.push_back(temp);
            temp.clear();
        }
        
        sort(distances.begin(), distances.end(), [](auto &left, auto &right) {
            return left[0] > right[0];
        });
        
        
        for (int i=distances.size()-1; k>0; k--){
            ans.push_back(points[distances[i][1]]);
            i--;
        }
        
        return ans;
    }
};