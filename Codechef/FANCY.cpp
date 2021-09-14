#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
const int mod = 1000000007;
int main()
{
   ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t;
cin>>t;
vector<ll>v;
 ll i,j,sum=0,act=0,k,n,q;
while(t--)
{
string a,b;
stringstream ss;
string c;

getline(cin,b);
if(b.length()==0)
{
    b.clear();
    getline(cin,b);
}
//cin.clear();
//cout<<b<<endl;
//cin.ignore(10000,'\n');


ss<<b;


int flag=0;
i=0;
while(ss>>a)
{
    
     //cout<<++i<<endl;
   // cout<<a<<endl;
    if((a=="Not" || a=="not") && a.length()==3)
    {
        
        flag=1;
    }
}
ss.str(string());
if(flag==1)
{
    cout<<"Real Fancy"<<endl;
}
else{
    cout<<"regularly fancy"<<endl;
}

}
return 0;
}
