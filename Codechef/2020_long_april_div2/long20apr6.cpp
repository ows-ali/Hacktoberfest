#include <bits/stdc++.h>
using  namespace std;
#define ll long long int
ll printRandoms(ll lower, ll upper)
{
       ll num = (rand() %(upper - lower + 1)) + lower;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    ll n,m,k;
    while(t--){
        cin>>n>>m>>k;
        vector<vector<ll>> vec(n,vector<ll>(k,0));
        for (ll i = 0; i <n ; ++i) {
            vector<int> mp(m+1,1);
            for (ll j = 0; j < k; ++j) {
                cin>>vec[i][j];
                mp[vec[i][j]]++;
            }
            sort(mp.begin(),mp.end(),greater<>());
            int pos=distance(mp.begin(),max_element(mp.begin(), mp.end()));
//                ll pos=printRandoms(1,m);
                cout<< pos<<" ";
        }
        cout<<'\n';
    }
    return  0;
}
