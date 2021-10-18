//The directions in which the rat can move are Up, Down, Left, Right

#include<bits/stdc++.h>
#define MAX 100005

using namespace std;

int xm[]={1,0,-1,0};
int ym[]={0,1,0,-1};
char ch[]={'D','R','U','L'};

bool isSafe(int x, int y, int n, int m[MAX][MAX]){
    if(x>=0 && x<n && y>=0 && y<n && m[x][y]!=0)
        return true;
    return false;
}

void solve(int x, int y, int n, int m[MAX][MAX], vector<string>
        &ans, string current){
    if(x == n-1 && y == n-1){
        ans.push_back(current);
        return;
    }
    
    for(int i=0; i<4; i++){
        int nextX = x+xm[i];
        int nextY = y+ym[i];
        if(isSafe(nextX, nextY, n, m)){
            current += ch[i];
            m[nextX][nextY] = 0;
            solve(nextX, nextY, n, m, ans, current);
            m[nextX][nextY] = 1;
            current.pop_back();
        }
    }
}

vector<string> printPath(int m[MAX][MAX], int n)
{
    string current;
    vector<string> ans;
    m[0][0] = 0;
    solve(0, 0, n, m, ans, current);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    
}