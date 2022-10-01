#include <bits/stdc++.h>
// problem:https://www.codechef.com/problems/REVERSE
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    // creating the graph
    vector<pair<int,int> >g[n+1];
    for(int i=0;i<m;++i)
    {
        int u,v;cin>>u>>v;
        g[u].push_back({v,0});
        g[v].push_back({u,1});
    }
    vector<int>lev(n+1,INT_MAX);

    // 0-1 bfs algorithm
    deque<int>dq;
    dq.push_back(1);
    lev[1]=0;
    while(!dq.empty()){
        int curr=dq.front();
        dq.pop_front();
        for(auto &x:g[curr]){
            int x_v=x.first;
            int x_wt=x.second;
            if(lev[curr]+x_wt<lev[x_v]){
                lev[x_v]=lev[curr]+x_wt;
                if(x_wt==1) dq.push_back(x_v);
                else dq.push_front(x_v);
            }
        }
    }
    if(lev[n]==INT_MAX) cout<<-1;
    else cout<<lev[n];
    return 0;
}
