#include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(--t>=0){
	    long long int n,k,i,c;
	    cin>>n>>k;
	    for(i=0;i<k;i++){
	        if(n%10!=9){
	            n++;}
	        else{
	            n=n-9;
	        }
	    }
	    cout<<n<<endl;
	}
	return 0;
}
