#include <bits/stdc++.h>
using  namespace std;
#define ll long long int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    ll n;
     while (t--){
        cin>>n;
        if(n==1)
            cout<<"1\n1 1\n";
        else
        {
            cout<<n/2<<"\n";
            if(n%2==0)
                cout<<"2 1 2\n";
            else
                cout<<"3 1 2 "<<n<<"\n";
            for (ll i = 3; i <n ; i+=2) {
                cout<<"2 "<<i<<" "<<i+1<<"\n";
            }
        }
    }
    return  0;
}
