//https://www.codechef.com/submit/LAZYCHF


#include <iostream>
using namespace std;

int main() {
	
	int t, x, m, d;
	cin>> t;
	
	while(t--)
	{
	    cin>> x >> m >> d;
	    
	    if((x*m) >= (x+d))
	    {
	        cout<< x+d <<endl;
	    }
	    else cout<< x*m <<endl;
	}
	
	return 0;
}