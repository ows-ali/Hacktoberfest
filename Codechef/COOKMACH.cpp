/* https://www.codechef.com/problems/COOKMACH  */

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        long long int a,b,count=0;
        cin>>a>>b;
        while(b%a){
            if(a%2){
                a=(a-1)/2;
                count++;
            }
            else{
                a=a/2;
                count++;
            }
        }
        while(a!=b){
            a*=2;
            count++;
        }
        cout<<count<<endl;
        
    }
	return 0;
}