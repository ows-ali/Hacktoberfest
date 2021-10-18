#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long max,int A, vector<int> C){
    int maxEle = *max_element(C.begin(),C.end());
    if(maxEle > max) return false;
    int cnt = 1;
    int n = C.size();
    int sum = 0;
    for(int i=0;i<n;){
        if(sum + (long long)C[i] > max){
            sum = 0;
            cnt++;
        }else{
            sum += (long long)C[i];
            i++;
        }
    }
    if(cnt <= A) return true;
    return false;
}
 
int paint(int A, int B, vector<int> &C) {
   long long start = 0,end = 0,ans = INT_MAX;
   for(int i=0;i<C.size();++i) end += C[i];
   while(start<=end){
       long long mid = (start + end)/2;
       if(isPossible(mid,A,C)){
           ans = min(mid,ans);
           end = mid-1;
       }
       else start = mid + 1;
   }
   return (ans * (long long) B) % 10000003;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;++i) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int k;
    cin>>k; 
    cout << paint(n, k, arr) << endl;
}