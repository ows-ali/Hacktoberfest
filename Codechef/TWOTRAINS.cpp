// https://www.codechef.com/submit/TWOTRAINS
// Solution to codechef problem asked in CONTEST AUG221


#include <iostream>
using namespace std;

int main() {
	int t;
	std::cin >> t;
	while(t--){
	    int n,s=0;
	    std::cin >> n;
	    int p[n-1];
	    for (int i = 0; i < n-1; i++) {
	        std::cin >> p[i];
	        s+=p[i];
	    }
	    int max=p[0];
	     for (int i = 0; i < n-1; i++) {
	        if(max<p[i]){
	            max=p[i];
	        }
	    }
	    std::cout << max+s << std::endl;
	    
	    
	}
	return 0;
}
