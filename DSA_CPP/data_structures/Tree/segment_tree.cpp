// problem Sereja and brackets
// Data structure used: Segment Tree
// problem link: https://codeforces.com/problemset/problem/380/C

#include<iostream>
#include<bits/stdc++.h>
// iteration and input/output stream

#define tc() int t; cin >> t ; while (t--)
//STL shortcuts
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define F first
#define S second
#define MP make_pair


using namespace std;

typedef long long int ll; // 64 bit integer
typedef unsigned long long int  ull; // 64 bit unsigned integer
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;

inline void smax(int &x , int y) { x = max(x , y) ; }
inline void smin(int &x , int y) { x = min(x , y) ; }

int t[2000005];
int ob[2000005];
int cb[2000005];
int n;
build()
{
    for(int i=n-1;i>0;i--)
    {
        t[i] = min(ob[2*i],cb[2*i+1])+t[2*i]+t[2*i+1];
        cb[i] = cb[2*i] + cb[2*i+1] - min(ob[2*i],cb[2*i+1]);
        ob[i] = ob[2*i] + ob[2*i+1] - min(ob[2*i],cb[2*i+1]);
    }
}

int query(int l, int r) {
    int res = 0;
    int  ol=0,orr=0,cl=0,cr=0;
  for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {

    if (l&1) {
            res = res+t[l]+ min(ol,cb[l]);
            ol = ol+ ob[l] - min(ol,cb[l]);
            cl = cl+ cb[l] - min(ol,cb[l]);
            l++;
    }
    if (!(r&1)){
            res = res+ t[r] + min(ob[r],cr) ;
            orr = orr + ob[r] - min(ob[r],cr);
            cr = cr + cb[r] - min(ob[r],cr);
            r--;
    };

  }
  return 2*res + 2*min(ol,cr);
}

int main()
{

    string s;
    cin>>s;
    n = s.size();
    for(int i=0;i<2000005;i++)
    t[i]=0;

    for(int i=0;i<n;i++)
    {
        char c;
        c = s[i];
        t[i+n]=0;
        if(c=='(')
            {ob[i+n] =1; cb[i+n]=0; }
        else
            {cb[i+n]=1; ob[i+n]=0; }
    }
    build();
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(l-1,r-1)<<endl;
    }
}
