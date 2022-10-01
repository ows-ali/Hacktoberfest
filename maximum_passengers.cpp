#include <bits/stdc++.h>
using namespace std;
int n, m;
int mat[105][105];
map<pair<int, pair<int, int>>, int> dp;
bool isValid(int i, int j)
{
    if (mat[i][j] == –1)
        return false;
    if (i < 0 || i >= n)
        return false;
    if (j < 0 || j >= m)
        return false;
    return true;
}
int solve(int i, int j, int x, int y)
{
    if (!isValid(i, j))
    {
        return INT_MIN;
    }
    if (!isValid(x, y))
    {
        return INT_MIN;
    }
    if (i == n – 1 && x == n – 1 && j == m – 1 && y == m – 1)
    {
        if (mat[i][j] == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp.find({i, {j, x}}) != dp.end())
        return dp[{i, {j, x}}];
 
    int cur = 0;
    if (i == x && j == y)
    {
        if (mat[i][j] == 1)
            cur = 1;
    }
    else
    {
        if (mat[i][j] == 1)
            cur++;
        if (mat[x][y] == 1)
            cur++;
    }
 
    int op1 = solve(i + 1, j, x + 1, y);
    int op2 = solve(i, j + 1, x, y + 1);
    int op3 = solve(i + 1, j, x, y + 1);
    int op4 = solve(i, j + 1, x + 1, y);
 
    int ans = cur + max(op1, max(op2, max(op3, op4)));
 
    return dp[{i, {j, x}}] = ans;
}
int main()
{
    cin >> n >> m;
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    int ans = solve(0, 0, 0, 0);
    if (ans >= 0)
        cout << solve(0, 0, 0, 0) << endl;
    else
        cout << –1 << endl;
 
    return 0;
}
