#include <bits/stdc++.h>
#define MAX_V 1000

using namespace std;

vector<int> G[MAX_V];
bool visited[MAX_V];

void bfs() {
    memset(visited, 0, sizeof visited);

    int initial_vertice = 0;

    queue<int> to_visit;
    to_visit.push(initial_vertice);
    visited[initial_vertice] = true;

    while(!to_visit.empty()) {
        auto v = to_visit.front();
        to_visit.pop();

        for (auto i: G[v]) {
            if (!visited[i]) {
                visited[i] = true;
                to_visit.push(i);
            }
        }
    }
}