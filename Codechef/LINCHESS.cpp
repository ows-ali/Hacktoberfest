//https://www.codechef.com/AUG20B/problems/LINCHESS

#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int a[1000];
	    int min=1000000000,min2=-1;
	    
	    for (int i=0;i<n;i++) {
	        /* code */
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(k%a[i]==0)
	        {
	            int temp = k/a[i]-1;
	            if(temp<min){
	                min =temp;
	                min2=a[i];
	            }
	        }
	    }
	    cout<<min2<<endl;
	}
	return 0;
}
