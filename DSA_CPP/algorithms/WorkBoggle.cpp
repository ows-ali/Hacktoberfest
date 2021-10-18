/*	
Word Boggle
Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.

Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

Output:  Following words of dictionary are present
         GEEKS, QUIZ

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. 
Each test case contains an integer x denoting the no of words in the dictionary. Then in the next line are x space 
separated strings denoting the contents of the dictinory. In the next line are two integers N and M denoting the 
size of the boggle. The last line of each test case contains NxM space separated values of the boggle.

Output:
For each test case in a new line print the space separated sorted distinct words of the dictionary which could be 
formed from the boggle. If no word can be formed print -1.

Constraints:
1<=T<=10
1<=x<=10
1<=n,m<=7

Example:
Input:
1
4
GEEKS FOR QUIZ GO
3 3
G I Z U E K Q S E

Output:
GEEKS QUIZ*/

#include <bits/stdc++.h>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

bool checkCorrespondence(string curr, vector <string> dict){
    return binary_search(dict.begin(),dict.end(),curr);
}

bool isItSafe(string curr, vector <string> dict, int n, int m, int i, int j){
    if(i < n and i >= 0 and j < m and j >= 0){
        loop(k,0,dict.size()){
            string temp = dict[k];
            int l = 0;
            for(l=0;l < min(curr.size(),temp.size());l++){
                if(temp[l] != curr[l]) break;
            }
            if(l == min(temp.size(),curr.size())){
            	return true;
            }
        }
    }
    
    return false;
}

bool boggleUtil(vector <vector <string> > grid, vector <string> dict, vector <vector <int> > &visited, int i, int j, string curr, vector <string> &solution){
    
    if(checkCorrespondence(curr,dict)){
        solution.push_back(curr);
    }
    //cout << i << " " << j << " " << curr << "\n";
    visited[i][j] = 1;
    int n = grid.size(),m = grid[0].size(); bool found = false;
    
    //south
    if(i != n-1 and isItSafe(curr+grid[i+1][j],dict,n,m,i+1,j) and !visited[i+1][j]){
        found = boggleUtil(grid,dict,visited,i+1,j,curr+grid[i+1][j],solution);
    }
    //south-east
    if(i != n-1 and j != m-1 and isItSafe(curr+grid[i+1][j+1],dict,n,m,i+1,j+1) and !visited[i+1][j+1]){
        found = boggleUtil(grid,dict,visited,i+1,j+1,curr+grid[i+1][j+1],solution);
    }
    //east
    if(j != m-1 and isItSafe(curr+grid[i][j+1],dict,n,m,i,j+1) and !visited[i][j+1]){
        found = boggleUtil(grid,dict,visited,i,j+1,curr+grid[i][j+1],solution);
    }
    //north-east
    if(i != 0  and j != m-1 and isItSafe(curr+grid[i-1][j+1],dict,n,m,i-1,j+1) and !visited[i-1][j+1]){
        found = boggleUtil(grid,dict,visited,i-1,j+1,curr+grid[i-1][j+1],solution);
    }
    //north
    if(i != 0 and isItSafe(curr+grid[i-1][j],dict,n,m,i-1,j) and !visited[i-1][j]){
        found = boggleUtil(grid,dict,visited,i-1,j,curr+grid[i-1][j],solution);
    }
    //north-west
    if(i != 0 and j != 0 and isItSafe(curr+grid[i-1][j-1],dict,n,m,i-1,j-1) and !visited[i-1][j-1]){
        found = boggleUtil(grid,dict,visited,i-1,j-1,curr+grid[i-1][j-1],solution);
    }
    //west
    if(j  != 0 and isItSafe(curr+grid[i][j-1],dict,n,m,i,j-1) and !visited[i][j-1]){
        found = boggleUtil(grid,dict,visited,i,j-1,curr+grid[i][j-1],solution);
    }
    //south-west
    if(i != n-1 and j != 0 and isItSafe(curr+grid[i+1][j-1],dict,n,m,i+1,j-1) and !visited[i+1][j-1]){
        found = boggleUtil(grid,dict,visited,i+1,j-1,curr+grid[i+1][j-1],solution);
    }
    
    visited[i][j] = 0;
    return found;
    
}

void boggle(vector <vector <string> > grid, vector <string> dict){
    int k = dict.size(), n = grid.size(), m = grid[0].size();
    
    vector <vector <int> > visited;
    vector <string> solution;
    loop(i,0,n){
    	vector <int> row(m);
    	visited.push_back(row);
    }
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m; j++){
            string curr = grid[i][j];
            boggleUtil(grid, dict, visited, i, j, curr, solution);
            //cout << endl;
        }
    }
    sort(solution.begin(),solution.end());
    loop(i,0,solution.size())
    	cout << solution[i] << " ";
    cout << endl;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int k = 0;
	    cin >> k;
	    vector <string> dictionary(k);
	    loop(i,0,k){
	        cin >> dictionary.at(i);
	    }
	    sort(dictionary.begin(),dictionary.end());
	    int n,m;
	    cin >> n >> m;
	    vector <vector <string> > grid;
	    loop(i,0,n){
	        vector <string> row(m);
	        loop(j,0,m) cin >> row.at(j);
	        grid.push_back(row);
	    }
	    
	    /*Testing cout << isItSafe("GEEKS", dictionary, 5, 5, 0, 0) << endl; */
	    boggle(grid, dictionary);
	}
	return 0;
}

