//Prime numbers using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector <int> prime(n+1);
    prime[0] = 1;
    prime[1] = 1;
    for(int i=2;i<=ceil(sqrt(n));i++)
    {
        if(prime[i]==0)
        {
            for(int j=2;i*j <= n;j++)
               prime[i*j] = 1;
        }
    }
    for(int j=0;j<=n;j++)
    {
        if(prime[j]==0)
        cout<<j<<" ";
    }
    return 0;
}