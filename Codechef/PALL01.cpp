#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int num=n;
	    int rem, rev=0;
	    while(num!=0){
	        rem=num%10;
	        rev=rev*10+rem;
	        num/=10;
	    }
	    if(rev==n){
	        cout<<"wins"<<endl;
	    }
	    else{
	        cout<<"loses"<<endl;
	    }
	    
	}
	return 0;
}