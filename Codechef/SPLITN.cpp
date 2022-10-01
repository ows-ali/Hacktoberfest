// The code is doing the following:
// * 1. It is taking the input as a long long integer.
// * 2. It is using the bitwise operator to check if the number is even or odd.
// * 3. If the number is even, then it will add 1 to the count.
// * 4. The count is printed.
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T>0)
	{
	    long long n;
	    cin>>n;
	    unsigned int c = 0;
	    while(n)
	    {
	        c = c + (n & 1);
	        n >>= 1;
	    }
	    cout<<c-1<<endl;
	    T--;
	}
	return 0;
}