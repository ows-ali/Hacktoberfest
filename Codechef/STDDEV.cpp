#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n, s,x;
    cin>>t;
    while(t--){
    	cin>>n>>s;
    	if(n==1 and s!=0){
    		cout<<-1<<endl;
    	}
    	else if(n==1 and s==0){
    		cout<<0<<endl;
    	}
    	else{

	    	if(n%2==0){
	    		x = n/2;
	    		while(x--){
	    			cout<<-s<<" ";
	    		}
	    		x = n/2;
	    		while(x--){
	    			cout<<s<<" ";
	    		}
	    	}
	    	else{
	    		float d = s* sqrt(n/((n-1)*1.0));
	    		x = n/2;
	    		while(x--){
	    			cout<<-d<<" ";
	    		}
	    		cout<<0<<" ";
	    		x = n/2;
	    		while(x--){
	    			cout<<d<<" ";
	    		}
	    	}
	    	cout<<endl;
	    }
    }
    
 
    return 0;
}
