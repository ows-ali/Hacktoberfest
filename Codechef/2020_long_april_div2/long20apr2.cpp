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
    ll n,z;
    while (t--) {
            cin>>n;
            vector<ll> vec;
            bool poss= false;
            ll count=0;
        for (ll i = 0; i <n ; ++i) {
            cin>>z;
            if(z==1)
                count++;
            vec.emplace_back(z);
        }
        ll prev=0,pos1=0;
        if(count==1)
            poss=true;
        else
       {
            if(n>=6){
            for (ll j = 0; j <n ; ++j) {
                if(vec[j]==1){
                    if(prev==0){
                        prev=1;
                        pos1=j;
                    }
                    else{
                        if(j-pos1>=6)
                        {
                            poss=true;
                            pos1=j;

                        } else{
                            poss= false;
                            break;
                        }
                    }

                }
            }
        }}
        if(poss)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return  0;
}


