#include <bits/stdc++.h>

using namespace std;
long a[400009];

int main() {
    
    int n;
    int m;
    cin >> n >> m;
    vector < pair < int, int > > v;
    
    for(int a0 = 0; a0 < m; a0++) {
    
        int a;
        int b;
        int k;
        cin >> a >> b >> k;
        
        //storing the query
        //this will add k in the prefix sum for index >= a
        v.push_back(make_pair(a, k));
        
        //adding -1*k will remove k from the prefix sum for index > b 
        v.push_back(make_pair(b+1, -1 * k));
    }
    
    long mx = 0, sum = 0;
    
    sort(v.begin(), v.end());
    
    for(int i=0 ; i<2*m; i++) {
    
        sum += v[i].second;
        mx = max(mx, sum);
        
    }
        
    cout<<mx<<endl;
    return 0;
}
