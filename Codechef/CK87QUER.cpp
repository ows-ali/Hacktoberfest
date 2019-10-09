#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t>0){
		long long y;
		cin>>y;
		long long sum=0;
		int i=1;
		while(i<=700 && sqrt(y-i)>0 && y-i>=0){
			sum=sum+sqrt(y-i);
			i++;
		}
		
		cout<<sum<<"\n";
		t--;
	}
	return 0;
}
