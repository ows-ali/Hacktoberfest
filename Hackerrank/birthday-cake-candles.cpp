#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int maximum=0,c=0;
    int arr[n];
    vector<int> v;
    for(auto i=0;i<n;i++){
        cin>>arr[i];
        v.push_back(arr[i]);
        maximum=max(maximum,arr[i]);
    }
   for(auto it=v.begin();it!=v.end();it++){
       if(maximum==*it){
           c++;
       }
   }
   cout<<c<<'\n';
    return 0;
}