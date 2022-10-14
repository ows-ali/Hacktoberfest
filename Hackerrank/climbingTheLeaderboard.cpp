#include<bits/stdc++.h>
typedef long long ll ;
#define int ll 
#define endl "\n"
#define mod 1000000007;
using namespace std ;

int modexp(int a,int b){
    int res=1;
    while(b>0){
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b=b>>1;    
    }
    return res;
}

signed main( ){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin>>n;
    set<int>s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
       int x=s.size();
       int a[x]; 
       int j=0;   
    for(auto i:s){
        a[j]=i;
        j++;
    }
       sort(a,a+x);
       // for(auto i:a)
           // cout<<i<<" ";
       // cout<<endl;
    int k;
    cin>>k;
    int b[k];
    for(int i=0;i<k;i++)
        cin>>b[i];
    
    for(int i=0;i<k;i++){        
        int y=upper_bound(a,a+x,b[i])-a;
        cout<<x-y+1<<endl;
    }
        
   
   
    
    
   
    

} 
