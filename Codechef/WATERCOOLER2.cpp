#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x,y,count=0;
	    cin>>x>>y;
	    int m=x;
	    if(y%x==0)
	        cout<<(y/x)-1<<endl;
	    else
	        cout<<y/x<<endl;
	}
	return 0;
}
