#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
typedef long long ll;

ll binaryExponentiation(ll A, ll B)
{   if (A == 0)
        return 0;
    if (B == 0)
        return 1;
    ll y;
    if (B % 2 == 0) {
        y = binaryExponentiation(A, B / 2);
        y = (y*y)%mod;
    }
    else {
        y = A % mod;
        y = (y * binaryExponentiation(A, B - 1) % mod) % mod;
    }

    return ((y + mod) % mod);
}

int gcdExtended(int a, int b, int *x, int *y);

int   modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);

        return (x%m + m) % m;

}

int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll a,b,c,d=0,e=0,g,f,h,t,n,k,m,z,o;
    const ll x=mod;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>m;
        d=0;
        e=binaryExponentiation(n-1,(m+1)/2)%x;
        f=binaryExponentiation(n,(m+1)/2);
        g=modInverse(f,x);
        d+=((1-(e*g)%x+x)%x);
        if(m%2==0)
        {
            f=f*(n+k)%x;
            g=modInverse(f,x);
            d+=(e*g)%x;
            d=d%x;
        }
        cout<<d<<endl;
    }
}
