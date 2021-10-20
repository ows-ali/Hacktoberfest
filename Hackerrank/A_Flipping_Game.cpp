//Do or do not, there is no try...!! -Yoda
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const ll int maxn = INT_MAX;
#define sgn(x,y) ((x)+eps<(y)?-1:((x)>eps+(y)?1:0))
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite freopen("output.txt","w",stdout)
#define read freopen("input.txt","r",stdin)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9
#define chk(p) cout<<p<<"\n"
#define maxof3(a,b,c) a>(b>c?b:c)?a:(b>c?b:c);
#define minof3(a,b,c) a<(b<c?b:c)?a:(b<c?b:c);
#define chkv(v) for(auto x:v){cout<<x<<" ";}cout<<"\n"
#define chkmp(mp) for(auto x:mp){cout<<x.first<<" "<<x.second<<"\n";}cout<<"\n"
#define intovec(v,n) for (ll int i = 0; i <n; ++i)cin>>v[i] //insert into vec v of size n
#define univmod(a, m) ((a%m + m) % m);

//-----end template--------


int main() {
    FASTER;
    int n,a,c1=0,c0=0,cmax0=-1;
    cin>>n;
    while(n--){
        cin>>a;
        if(a==1){
            c1++;
            if(c0>0){
                c0--;
            }
        }
        if(a==0){
            c0++;
            if(c0>cmax0)
                cmax0=c0;
        }
    }
    int ans=c1+cmax0;
    cout<<ans<<endl;
    

return 0;
}


 
