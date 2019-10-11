/**
https://www.hackerrank.com/challenges/gridland-metro/problem
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> llp;
typedef pair<ll,llp> llip;
typedef map <ll,llip> mlli;

int main() {
  
  ll n,m,k,r,from,to; 
  scanf("%lld %lld %lld",&n,&m,&k);
  ll totalLamps = n*m, totalTrakcs = 0;
  //map tracks is used to track the cell occupying the tracks 
  //map is used to input the track coordinates and store the tracks such that it mantains the count of occupied cells
  mlli tracks;
  for (int i = 0; i < k; ++i)
  {
    scanf("%lld %lld %lld", &r, &from, &to);
    if(!tracks.count(r))
    {
      tracks[r].first = (to - from) + 1; 
      tracks[r].second.first = from; 
      tracks[r].second.second = to;
    }
    else
    {
      if((from <= tracks[r].second.second &&  from >= tracks[r].second.first) || (to >= tracks[r].second.second &&  to <= tracks[r].second.first)){
        if(tracks[r].second.first > from)
          tracks[r].second.first = from;
        if(tracks[r].second.second < to)
          tracks[r].second.second = to;
        tracks[r].first = (tracks[r].second.second - tracks[r].second.first) + 1;
      }
      else
      {
        tracks[r].first += (to - from) + 1;
      }
    }
  }

  for (mlli::iterator it=tracks.begin(); it!=tracks.end(); ++it){
    totalTrakcs += it->second.first;
  }

  
  cout<<totalLamps - totalTrakcs<<endl;
  return 0;
}
