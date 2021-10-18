#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<string>
#define  ll long long int
#define loop(i,n) for(i=0;i<n;i++)
#define loop1(i,s,e) for(ll i=s;i<=e;i++)
#define io std::ios::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define rep(i,c) for(typeof(c.begin())i=c.begin();i!=c.end();++i)
#define pb push_back
#define pii pair<ll,ll>
using namespace std;
#define MAX 109
#define INF 1000000000000000
int tree[2000005],A[100005];
void build(int node,int start,int end)
{
    if(start==end)
        tree[node]=A[start];
    else
    {
    int mid=(start+end)/2;
    
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    
    tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
void update(int node,int start,int end,int idx,int val)
{
    if(start==end)
    {   
        A[idx]=val;
        tree[node]=val;
    }
    else
    {   
        int mid=(start+end)/2;
        
        if(idx>=start && idx<=mid)
        update(2*node,start,mid,idx,val);
        
        else
        update(2*node+1,mid+1,end,idx,val);
        
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
int query(int node,int start,int end,int l,int r)
{
    if(start>r || end<l)
    return 100005;
    
    if(l<=start && r>=end)
    return tree[node];
    
    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node+1,mid+1,end,l,r);

    return min(p1,p2);
}
int main()
{   
    int n,q,i,idx,val,l,r;
    char type;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    cin>>A[i];
    build(1,1,n);
    while(q--)
    {
        cin>>type;
        if(type=='u')
        {
            cin>>idx>>val;
            update(1,1,n,idx,val);
        }
        else
        {
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
}
