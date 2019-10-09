#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	float c, h, t;
	cin>>n;
	while(n--){
	    cin>>h>>c>>t;
	    if( h > 50 && c < 0.7 && t > 5600)   cout<<"10"<<endl;
	    else if( h > 50 && c < 0.7 && t <= 5600)   cout<<"9"<<endl;
	    else if( h <= 50 && c < 0.7 && t > 5600)   cout<<"8"<<endl;
	    else if( h > 50 && c >= 0.7 && t > 5600)   cout<<"7"<<endl;
	    else if( h > 50 || c < 0.7 || t > 5600)   cout<<"6"<<endl;
	    else if( h <= 50 && c >= 0.7 && t <= 5600)  cout<<"5"<<endl;
	}
	return 0;
}
