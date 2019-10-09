#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t, a,b;
	cin>>t;
	while(t--){
	    cin>>a>>b;
	    int max=0;
	    for(int i=1; i<=b; i++){
	        if((a%i)>max)
	            max=a%i;
	    }
	    cout<<max<<endl;
	}
	return 0;
}
