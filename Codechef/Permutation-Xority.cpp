#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	while(n--){
	    int p;
	    cin>>p;
	    if(p==2){
	        cout<<-1<<endl;
	    }
	    else if(p%2!=0){
	        for(int i=1;i<=p;i++){
	            cout<<i<<" ";
	        }
	        cout<<endl;
	    }
	    else{
	        cout<<2<<" "<<3<<" "<<1<<" ";
	         for(int i=4;i<=p;i++){
	            cout<<i<<" ";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
