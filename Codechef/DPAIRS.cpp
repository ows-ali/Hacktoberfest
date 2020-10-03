//https://www.codechef.com/problems/DPAIRS/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,m,sum = 0,c = 0,f = 0;
    map<long long int,long long int> mp;
    vector <pair<long long int,long long int> > v1,v2;

    cin >> n >> m;
    long long int a[n],b[m],e;
    long long int r = n+m-1;
    for(int i = 0; i < n; i++){
        cin >> e;
        v1.push_back(make_pair(e,i));
    }
    for(int j = 0; j < m; j++){
        cin >> e;
        v2.push_back(make_pair(e,j));
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    for(int i = 0; i < v1.size(); i++){
        for(int j = v2.size() - 1; j >= 0; j--){
            sum = v1[i].first + v2[j].first;
            if(mp[sum] != 1){
                mp[sum] = 1;
                cout << v1[i].second << " " << v2[j].second;
                cout << endl;
                c++;
                if(c == r){
                    f = 1;
                    break;
                }
            }
            else
                break;
        }
        if(f == 1)
            break;
    }

}
