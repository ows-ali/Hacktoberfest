// https://www.codechef.com/problems/SMALLXOR

#include<bits/stdc++.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;
typedef unsigned long long ll;
typedef unsigned long long int ulli;
typedef long long int lli;

int main() {
    unsigned long long int t;

    cin >> t;

    while (t--) {
        lli n,x,y;
        cin>>n>>x>>y;
        priority_queue<lli> pq;
        for(lli i=0;i<n;++i){
            lli temp;
            cin>>temp;
            pq.push(-1*temp);
        }

        while(y>0){
            lli temp = pq.top();
            if(((-1*temp)^x)>(-1*temp)){
                pq.pop();
                pq.push(-1*((-1*temp)^x));
                y--;
            }
            else
                break;
        }
        if(y%2!=0){
            lli temp = pq.top();
            pq.pop();
            pq.push(-1*((-1*temp)^x));
        }

        while(!pq.empty()){
            cout<<(-1*pq.top())<<" ";
            pq.pop();
        }
        cout<<endl;
    }
    return 0;
}