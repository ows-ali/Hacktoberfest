#include <bits/stdc++.h>
#define cinarr(a,n) for(int i = 0; i < n; i++) cin >> a[i] 
#define coutarr(a) for(int i = 0; i < n; i++) cout << a[i] <<endl 
#define intin(x) int x ; cin >> x ; 
#define strin(x) string x ; cin >> x ; 
#define print(x) cout << x <<endl ;
#define loop(i,a,n) for (int i=a;i<n;i++)
#define ll long long
#define int long long
#define YES cout << "Yes" <<endl ;
#define NO cout << "No" <<endl ;
#define endl "\n" ;
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define qi queue<int>
#define mii map<int,int>
#define pii pair<int,int>
#define mip map<int,pair<int,int>>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
//Smuggler
//My  Will is Eternal 
const int N =32768;
//------------------------------------------------------xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx--------------------------------------------------------------------------------------------
 
 
 
 
 
 
 
 
void solve ()
{ 
 int p,q,r ; 
 cin >> p >> q >>r ; 

 int sum= 1  ;

 loop (i,0,30)
 {
  int x =  ((p>>i)&1 )  + ((q>>i)&1 ) + ((r>>i)&1 ) ;
  // cout <<x <<endl ;
  if (x==3)
  {
    sum*=4 ;
  }
  else if (x==1)
  {
    sum=0 ;
    break ;
  }
   
 }
 cout <<sum <<endl ;

}
signed main()
    {   SYNC ;
      // #ifndef ONLINE_JUDGE
      // freopen("shell.in", "r", stdin);
      // freopen("shell.out", "w", stdout);
      // #endif     
        int t =1; 
       cin >> t;
        while (t--)
          {
            solve() ;
          }
        return 0 ;
    }