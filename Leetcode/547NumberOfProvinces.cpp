#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    
    int result = 0;
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int N = isConnected.size();
        vector<int> isVisited(N, 0);
        
        int result = 0;
        for(int i = 0; i < N; i++) {
            if(isVisited[i]) continue;
            
            result += 1;            
            dfs(isConnected, isVisited, i);
        }
        
        return result;
        
    }
    
    void dfs(vector<vector<int>>& isConnected, vector<int>& isVisited, int current) {
        
        for(int i = 0; i < isVisited.size(); i++) {
            if(i == current || isConnected[current][i] == 0 || isVisited[i] == 1) continue;
            
            isVisited[i] = 1;
            dfs(isConnected, isVisited, i);
        }
    }
};