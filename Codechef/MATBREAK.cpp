#include<bits/stdc++.h>
using namespace std;

int power(long long int x, long long int y)  //X^P MOD P
{  
    long long int res = 1;    
  	long long int p=1000000007;
    x = x % p; 
   
    if (x == 0) return 0; 
  
    while (y > 0)  
    {  
       
        if (y & 1)  
            res = (res*x) % p;  
  
        
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
}

int main()
{
	int t;
	cin>>t;
	long long int p=1000000007;
	while(t!=0)
	{
		t--;
		long long int a,n;
		cin>>n>>a;
		//vector<vector<int>> v(n,vector<int> (n,a));
	/*	long long int prod[n];//store all p's in this array
		long long int temp=0;
		prod[0]=a;
		
		for(int i=1;i<n;i++)
		{
			
			temp=(prod[i-1])%p*(power(a,i))%p;
			
			prod[i]=power(temp,(2*(i+1)-1));
		}
		
		long long int sum=0;
		for(int i=0;i<n;i++)
		{
			sum=(sum+prod[i])%p;
		}
		cout<<sum<<endl;
		*/
		unsigned long long ans=0;
		long long int count =1;
		while(n>0){
			unsigned long long cal= power(a,count);
			cal = cal%1000000007;
			ans = (ans+cal)%1000000007;
			a = (a*cal)%1000000007;
			count = count+2;
			n--;
			}
		cout<<ans<<endl;
	}
	return 0;
}	
