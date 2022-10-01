#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
/*---------------------------------------------------------------------------------------------------------------------------*/
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define nl "\n";
#define PI 3.141592653589793238462
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
/*---------------------------------------------------------------------------------------------------------------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) { if (b == 0) {return a;} return gcd(b, a % b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
/*---------------------------------------------------------------------------------------------------------------------------*/

//hcf is same as gcd
int hcf(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return hcf(b,a%b);
}

//finding power using binary exponentiation
long long power(long long int a,long long int b)
{
    long long ans,c;
    ans=1;
    c=a;
    while(b>0)
    {
        if((b&1)!=0)
        {
            ans=ans*c;
            ans=ans%1000000007;
        }
        c=c*c;
        c=c%1000000007;
        b=(b>>1);
    }
    return ans;
}

void solve() 
{
    long long int n,i,j,k,g,p,h,q;
    vector<long long int> v,a,b,s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>g;
        v.push_back(g);
        a.push_back(0);
    }
    for(i=0;i<1000000;i++)
    {
        s.push_back(i);
    }
    // using sieve of eratosthenes algo
    s[0]=-1;
    s[1]=1;
    for(i=2;i<1000;i++)
    {
        if(s[i]==i)
        {
            for(j=i*i;j<1000000;j+=i)
            {
                if(s[j]==j)
                s[j]=i;
            }
        }
    }
    p=1;
    for(i=0;i<n;i++)
    {
        j=i;
        k=0;
        g=0;
        while(a[j]==0)
        {
            g=1;
            a[j]=1;
            j=v[j]-1;
            k++;
        }
        if(k!=0)
        {
            b.push_back(k);
        }
        //cout<<k<<"\t";
    }
    h=b.size();
    p=1;
    map<long long,long long> mp;
    for(i=0;i<h;i++)
    {
        q=b[i];
        map<long long,long long> pm;
        while(s[q]!=q)
        {
            //cout<<s[q]<<" ";
            pm[s[q]]++;
            q=q/s[q];
        }
        pm[q]++;
        //cout<<q<<" ";
        for(auto vp: pm)
        {
            //cout<<vp.first<<"\n";
            if(mp[vp.first]<vp.second)
            {
                mp[vp.first]=vp.second;
            }
        }
        pm.clear();
    }
    for(auto vc: mp)
    {
        q=power(vc.first,vc.second);
        p=p*q;
        p=p%1000000007;
    }
    cout<<p<<"\n";
}
int main()
{
    int t;
    fastio();
    cin>>t;
    while(t--)
    {
        solve();
    }
}
