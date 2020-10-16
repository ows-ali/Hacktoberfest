#include <bits/stdc++.h>
using  namespace std;
#define ll long long int
#define fo(i,n) for(auto i=0;i<n;i++)
#define mod 1000000007


ll divCount(ll n)
{
    // sieve method for prime calculation
    bool hash[n + 1];
    memset(hash, true, sizeof(hash));
    for (ll p = 2; p * p < n; p++)
        if (hash[p])
            for (ll i = p * 2; i < n; i += p)
                hash[i] = false;

    // Traversing through all prime numbers
    ll total = 1;
    for (ll p = 2; p <= n; p++) {
        if (hash[p]) {

            ll count = 0;
            if (n % p == 0) {
                while (n % p == 0) {
                    n = n / p;
                    count++;
                }
                total = total * (count + 1);
            }
        }
    }
    return total;
}

void addEdge(vector<ll> v[],ll x,ll y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}

// A function to prll the path between
// the given pair of nodes.
void printPath(vector<ll> stack)
{
    ll i,num=1;
    for (i = 0; i < (ll)stack.size() - 1;
         i++) {
        num*=stack[i];
    }
    num*=stack[i];
    cout<<divCount(num);
}

// An utility function to do
// DFS of graph recursively
// from a given vertex x.
void DFS(vector<ll> v[],
         bool vis[],
         ll x,
         ll y,
         vector<ll> stack)
{
    stack.push_back(x);
    if (x == y) {

        // prll the path and return on
        // reaching the destination node
        printPath(stack);
        return;
    }
    vis[x] = true;

    // A flag variable to keep track
    // if backtracking is taking place
    ll flag = 0;
    if (!v[x].empty()) {
        for (ll j = 0; j < v[x].size(); j++) {
            // if the node is not visited
            if (!vis[v[x][j]]) {
                DFS(v, vis, v[x][j], y, stack);
                flag = 1;
            }
        }
    }
    if (flag == 0) {

        // If backtracking is taking
        // place then pop
        stack.pop_back();
    }
}

// A utility function to initialise
// visited for the node and call
// DFS function for a given vertex x.
void DFSCall(ll x,ll y,vector<ll> v[],ll n,vector<ll> stack)
{
    // visited array
    bool vis[n + 1];

    memset(vis, false, sizeof(vis));

    // DFS function call
    DFS(v, vis, x, y, stack);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    ll n,z,q;
    ll a,b;
    while(t--){
       cin>>n;
        vector<ll> arr,temp;
        vector<vector<ll>> vec(n+1);
        vector<ll> v[n+1];
        for (ll i = 0; i <n-1 ; ++i) {
            cin>>a>>b;
            vec[a].emplace_back(b);
            addEdge(v,a,b);
        }
        fo(i,n){
            cin>>z;
            arr.emplace_back(z);
        }
        cin>>q;

        ll num;
        fo(i,q){
            cin>>a>>b;
            num=1;
            vector<ll> stack;
            if(a==b){
               divCount(arr[a-1]);
            } else{
                DFSCall(a, b, v, n, stack);
            }
            cout<<endl<<"h";
//            cout <<divCount(num)%mod<<'\n';
//            vec.emplace_back(z);
        }
    }
    return  0;
}

