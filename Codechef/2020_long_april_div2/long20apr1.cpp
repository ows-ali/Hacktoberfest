#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t ;
    cin >> t ;
    ll n;
    while (t--) {
        cin>>n;
        vector<ll> vec;
        ll z,profit=0;
        for (ll i = 0; i < n; ++i) {
            cin>>z;
            vec.emplace_back(z);
        }
        sort(vec.begin(),vec.end(),greater<>());
        profit+=vec[0];
        for (ll j = 1; j < n; ++j) {
            if(vec[j]-j>0)
            profit+=(vec[j]-j);
            else
                break;
        }
        cout<<profit%mod<<"\n";
    }
    return  0;
}


