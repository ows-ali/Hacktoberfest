/*
--------------Solution 1 - using dfs--------------
*/

class Solution
{
public:
    bool dfs(int curr, int parent, bool visited[], int color[], vector<vector<int>> &adj)
    {
        color[curr] = parent == -1 ? 0 : !color[parent];

        visited[curr] = true;

        for (auto next : adj[curr])
        {
            if (visited[next] && color[next] == color[curr])
                return false;
            if (!visited[next] && !dfs(next, curr, visited, color, adj))
            {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &adj)
    {
        int V = adj.size();
        int color[V];
        bool visited[V], ans = true;
        memset(color, -1, sizeof(color));
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                ans = ans && dfs(i, -1, visited, color, adj);
            }
        }

        return ans;
    }
};

/*
--------------Solution 2 - Space optimized since no need of visited array--------------
*/

class Solution
{
public:
    bool dfs(int curr, int parent, int color[], vector<vector<int>> &adj)
    {
        color[curr] = parent == -1 ? 0 : !color[parent];

        for (auto next : adj[curr])
        {
            if (color[next] == color[curr] || color[next] == -1 && !dfs(next, curr, color, adj))
                return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &adj)
    {
        int V = adj.size();
        int color[V];
        memset(color, -1, sizeof(color));

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1 && !dfs(i, -1, color, adj))
            {
                return false;
            }
        }

        return true;
    }
};

/*
--------------Solution 3 - using bfs--------------
*/

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &adj)
    {
        int V = adj.size();
        int color[V];
        memset(color, -1, sizeof(color));

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                queue<int> q{};
                q.push(i);
                color[i] = 0;

                while (!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    for (auto next : adj[curr])
                    {
                        if (color[next] == color[curr])
                            return false;
                        if (color[next] == -1)
                        {
                            color[next] = !color[curr];
                            q.push(next);
                        }
                    }
                }
            }
        }

        return true;
    }
};
