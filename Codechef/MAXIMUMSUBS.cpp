// The code is doing the following:
// * 1. It reads the number of test cases T.
// * 2. For each test case, it reads the value of x.
// * 3. It prints the result as 2*x.
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T>0)
	{
	    int x;
	    cin>>x;
	    cout<<2*x<<endl;
	    T--;
	}
	return 0;
}