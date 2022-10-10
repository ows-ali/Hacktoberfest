#include <bits/stdc++.h>
#define int long long int
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;
void solve() {
    int num;
    cin>>num;
    string S;
    cin>>S;
    string s1,s2;
    for(int i=0; i<num; i++)
    {
        if(isdigit(S[i]))
        {
            s1.push_back(S[i]);
        }
        else
        {
            s2.push_back(S[i]);
        }
    }
    sort(s1.begin(),s1.end());
    reverse(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    int k= s2.length(),l=s1.length();
    for(int i=0; i<l-k; i++)
    {
        cout<<s1[i];
    }
    for(int z=0, j=l-k; z<k,j<l; j++,z++)
    {
        cout<<s2[z]<<s1[j];
    }
    cout<<"\n";
}
signed main() {
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
int t;
cin >> t;
while (t--) {
 solve();
}
return 0;
}