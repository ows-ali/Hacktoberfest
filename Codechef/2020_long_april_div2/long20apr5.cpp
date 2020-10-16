#include <bits/stdc++.h>
using  namespace std;
#define ll long long int
ll sumArr(vector<ll>arr, ll n, ll sum)
{
    unordered_map<ll, ll> prevSum;

    ll res = 0;

    // Sum of elements so far.
    ll currsum = 0;

    for (ll i = 0; i < n; i++) {

        currsum += arr[i];
        if (currsum == sum)
            res++;

        if (prevSum.find(currsum - sum) !=
            prevSum.end())
            res += (prevSum[currsum - sum]);
        prevSum[currsum]++;
    }

    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    ll n,z;
    ll count,mul,odd,even4,even;
    while (t--){
        cin>>n;
        odd=0;even4=0;
        even=0;
        vector<ll> vec,arr;
        ll total =(n*(n+1))/2;
        for (ll i = 0; i <n ; ++i) {
            cin >> z;
//            vec.emplace_back(abs(z));
            if(z%4==0)
                arr.emplace_back(2);
            else if(z%2==0)
                arr.emplace_back(1);
            else
                arr.emplace_back(0);
        }
        for (ll j = 0; j <n ; ++j) {

        }
        ll minus=sumArr(arr,n,1);

        cout<<total-minus<<"\n";
    }
    return  0;
}
