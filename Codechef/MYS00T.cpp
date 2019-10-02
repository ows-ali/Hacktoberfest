//https://www.codechef.com/problems/MYS00T
//Problem Name: Mystery Tree

#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ppi pair<int,pi >
#define ppl pair<ll,pl >
#define ld long double
#define pb push_back
#define mod 1000000007

int dfs(vector<int> tree[], int u, bool vis[], int n, int &ans)
{
    vis[u]=1;
    int count=0;
    int sum=0;
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(vis[v])
            continue;
        int val=dfs(tree,v,vis,n,ans);
        count=max(count,val);
        sum+=val;
    }
    int rem=n-sum-1;
    count=max(rem,count);
    if(count<=n/2 && ans==-1)
    {
        ans=u;
    }
    return sum+1;
}

int dfs2(vector<int> tree[], int u, bool visited[])
{
    visited[u]=1;
    int ans=0;
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(visited[v])
            continue;
        ans+=dfs2(tree,v,visited);
    }
    return ans+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> tree[n+1];
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            tree[u].pb(v);
            tree[v].pb(u);
        }
        int start=1;
        int N=n;
        do{
            int ans=-1;
            bool vis[n+1]={0};
            dfs(tree,start,vis,N,ans);
            cout<<1<<" "<<ans<<endl;
            int temp;
            cin>>temp;
            if(temp==-1)
            {
                cout<<2<<" "<<ans<<endl;
                cin>>temp;
                break;
            }
            for(auto it=tree[ans].begin();it!=tree[ans].end();it++)
            {
                if((*it)==temp)
                {
                    tree[ans].erase(it);
                    break;
                }
            }
            for(auto it=tree[temp].begin();it!=tree[temp].end();it++)
            {
                if((*it)==ans)
                {
                    tree[temp].erase(it);
                    break;
                }
            }
            start=temp;
            bool visited[n+1]={0};
            N=dfs2(tree,temp,visited);
        }while(1);
        
    }

    return 0;
}
