#include<bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mod 1000000007
using namespace std;


int main() {
   int t;
   cin >> t;
   while(t--){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        pair<int,int> p;
        p.first = a[i];
        p.second = b[i];
        ans.pb(p);
    }
    int sum = 1;
    sort(ans.begin(),ans.end());
    int maxi = ans[n-1].second;
    for(int i=n-2;i>-1;i--){
        if(ans[i].second>maxi){
            sum++;
            maxi = ans[i].second;
        }
    }
    cout << sum << "\n";
   }
   return 0;
}