/*This program is from Code-Quidditch

https://www.hackerearth.com/challenges/college/Code-Quidditch/algorithm/222b311dff8842c0803a5aee84096a37/

*/

//Program

#include<iostream>
#include<math.h>
using namespace std;

long long modular(long long base, long long exp, int mod) {
   long long res = 1;
   while (exp > 0) {
      if (exp % 2 == 1)
         res= (res * base) % mod;
      exp = exp >> 1;
      base = (base * base) % mod;
   }
   return res;
}
int main()
{
    long int n,sum=0,a,b;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        sum=sum+(i*(modular(2,i,1000000007)));
    }
    cout<<sum%1000000007;
}
