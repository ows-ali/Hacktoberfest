//SCC: Strongly Connected Components
/*We can find all strongly connected components in O(V+E) time using Kosaraju’s algorithm.
A directed graph is strongly connected if there is a path between all pairs of vertices in the graph
can also be done by johnson algorithm and tarzan algorithm*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
stack<int > s,s1;
vector<int> adj[1000],tadj[1000];
int visit[1000]={0},done[1000]={0};
int cur;
int rdfs(ll x)
{
    visit[x]=1;
    for(int j=0;j<adj[x].size();j++)
        if(!visit[adj[x][j]])
          rdfs(adj[x][j]);
    s.push(x);
}
int dfs(int x)
{
    s1.push(x);
    cout<<x<<" ";
    done[x]=1;
    for(int j=0;j<tadj[x].size();j++)
        if(!done[tadj[x][j]])
            dfs(tadj[x][j]);
}
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
        tadj[y].pb(x);
    }
    for(int i=1;i<=n;i++)
       if(visit[i]==0)
         rdfs(i);

    while(!s.empty())
    {
        int t=s.top();
        s.pop();
        while(!s1.empty()) s1.pop();//doubt full line
        if(!done[t]) dfs(t);
        cout<<endl;
    }
}

