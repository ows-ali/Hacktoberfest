#include <iostream>
#include <utility>
using namespace std;

class triplet{
public:
	int gcd;
	int x; 
	int y;
};

triplet gcdExtendedEuclid(int a, int b){
	// Base case
	if(b == 0){
		triplet myAns;
		myAns.gcd = a;
		myAns.x = 1;
		myAns.y = 0;

		return myAns;
	}

	triplet smallAns = gcdExtendedEuclid(b, a%b);

	// Extended Euclid says

	triplet myAns;
	myAns.gcd = smallAns.gcd;
	myAns.x = smallAns.y;
	myAns.y = smallAns.x - ((a/b) * smallAns.y);

	cout << myAns.x << " * " << a << " + " <<myAns.y << " * " << b << " = " << myAns.gcd << endl;
	return myAns;
}

// Using Euclidien Algorithm
int gcd(int a,int b){
	if(a<b){
		swap(a,b);
	}

	if(a % b == 0){
		return b;
	}
	return gcd(b , a % b);
}



int main(){
	int x, y;

	cin >> x >> y;

	cout << gcd(x,y) << endl;

	triplet ans = gcdExtendedEuclid(x, y);

	cout << endl << "ANSWER : " << ans.x << " * " << x << " + " << ans.y << " * " << y << " = " << ans.gcd;



}