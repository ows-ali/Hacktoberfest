// Link to problem - https://www.spoj.com/problems/AGGRCOW/
// AGGRCOW - Aggressive cows
// Please refer https://www.youtube.com/watch?v=TC6snf6KPdE for better understanding.
// Also go through- https://www.topcoder.com/community/competitive-programming/tutorials/binary-search

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--){
    int n,c,i,k;
    cin>>n>>c;
    int a[n];
    for(i=0;i<n;i++){
      cin>>a[i];
    }
    sort(a,a+n);
    int lo,hi;
    lo=0;
    hi=a[n-1]-a[0];
    int fi;
    int d;
    while(lo<=hi){
      int mid=lo+(hi-lo)/2;
      int temp=1;
      fi=a[0];
      for(i=1;i<n;i++){
        if(a[i]-fi>=mid){
          temp++;
          fi=a[i];
        }
      }
      if(temp<c){
        hi=mid-1;
      }else{
        d=mid;
        lo=mid+1;
      }
    }
    cout<<d<<"\n";
  }
  return 0;
}
