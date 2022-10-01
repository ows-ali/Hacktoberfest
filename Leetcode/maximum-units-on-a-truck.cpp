//https://leetcode.com/problems/maximum-units-on-a-truck/submissions/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(vector<int>& a, vector<int> & b)
    {
        if(a[1] == b[1])
            return a[0] >= b[0];
        
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        int sum=0,count=0;
         sort(boxTypes.begin(), boxTypes.end(), compare);
         for(int i = 0; i<boxTypes.size() && truckSize!=0; i++){
                truckSize-=boxTypes[i][0];
                sum+=boxTypes[i][1]*boxTypes[i][0];
                 if(truckSize<0)
             {
                 sum+=boxTypes[i][1]*truckSize;
                 break;
             }
                }
        return sum;
    }
};