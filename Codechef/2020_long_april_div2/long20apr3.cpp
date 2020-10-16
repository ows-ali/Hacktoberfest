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
    ll x,k;
    while (t--) {
            cin>>x>>k;
            unordered_map<ll,ll> umap;
            ll n=x;
        while (n % 2 == 0)
        {
           umap[2]++;
            n = n/2;
        }
        for (ll i = 3; i <= sqrt(n); i = i + 2)
        {
            while (n % i == 0)
            {
                umap[i]++;
                n = n/i;
            }
        }
        ll sum=0;
        if (n > 2)
           umap[n]++;
        for (auto part : umap){
            sum+=part.second;
        }
        if(x>=pow(2,k)&&k<=sum)
            cout<<"1\n";
        else
            cout<<"0\n";

    }
    return  0;
}


