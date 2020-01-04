#include <bits/stdc++.h>
#include<vector>
#define ll long long int
#define fr(s,e) for(ll i=s;i<e;i++)
#define mod 1000007
using namespace std;
bool comparator(const pair<ll, ll>&i,const pair<ll, ll>&j)
{
    return (i.first>j.first);
}
ll sumn(ll m)
{
        ll sum=0;
        while(m>0)
        {
            sum=sum+(m%10);
            m=m/10;
        }
        return sum;
}
void reverseArray(ll arr[], ll start, ll end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // freopen("input.txt","r",stdin);
//    freopen("output1.txt","w",stdout);
    ll t,k=1;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll i,c=0;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='1')
                c++;
        }
        if(c%2==0)
            cout<<"LOSE"<<endl;
        else
            cout<<"WIN"<<endl;
    }
    return 0;
}




