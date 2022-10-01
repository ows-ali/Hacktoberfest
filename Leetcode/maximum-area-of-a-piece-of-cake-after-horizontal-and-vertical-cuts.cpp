//https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/submissions/
 
 #include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long int cut1=0,cut2=0;
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        for(int i=1; i<horizontalCuts.size(); i++){
            if (cut1 < horizontalCuts[i] - horizontalCuts[i-1]){
                cut1 = horizontalCuts[i] - horizontalCuts[i-1];
            }
        }
        for (int i=1; i<verticalCuts.size(); i++){
            if(cut2 < verticalCuts[i] - verticalCuts[i-1]){
                cut2 = verticalCuts[i] - verticalCuts[i-1];
            }
        }
                     return ((cut1*cut2)%1000000007);
    }
};