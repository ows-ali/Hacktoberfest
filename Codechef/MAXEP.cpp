#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int mod = 1000000007;

int main()
{
   ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll n,c;
cin>>n>>c;
ll low=1,high=n,mid,x,a=1000,prev=0,flag=0,i=1,val=sqrt(n),ele=val;
while(flag==0 && a>0)
{
if(ele*i>n)
{
    val=n;
    flag=2;
}
else
{
    val=ele*i;
}
cout<<"1 "<<val<<endl;
cin>>x;
a--;
if(x==0)
{
    i++;
}
else
{
    a-=c;
    cout<<"2"<<endl;
    break;
}

}
val=ele*(i-1);
if(val==0)
{
    val++;
}
while(val<n && a>0)
{
    cout<<"1 "<<val<<endl;
    cin>>x;
    ele=x;
    a--;
    if(x==0)
    {
val++;
    }
    else
    {
break;
    }
}
a-=c;
cout<<"3 "<<val<<endl;

return 0;
}


