// Program for checking whether given number is a prime or not(Primality Testing) in O(sqrt(n)).

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
	if(n < 2)	return false;
	if(n == 2)	return true;
	for(int i=3; i<=sqrt(n); i+=2)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cout << "Enter any number: ";
	cin >> n;
	if(isPrime(n))	cout << "It is a prime number." << endl;
	else	cout << "It's not a prime number!" << endl;
	return 0;
}
