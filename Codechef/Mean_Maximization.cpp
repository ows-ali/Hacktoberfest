/*=============================================================================
#  Author:          saurabhcodes25
#  Problem Link:    https://www.codechef.com/COOK137C/problems/MEANMAX
=============================================================================*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl     "\n"    
#define MOD      1e9+7

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        double sum=0,arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        sort(arr,arr+n);
        sum-=arr[n-1];
        sum=sum/(n-1);
        cout<<setprecision(12)<<fixed<<sum+arr[n-1]<<endl;
    }
    
    return 0;
}