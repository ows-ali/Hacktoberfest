#include<iostream>
#include<cmath>
#include<string>

double off(float billPrice, float disc);

int main()
{
	system("color 0A");
	using namespace std;

	float billPrice;

		cout << "\nEnter the bill value\n";
		cin >> billPrice;

		if (billPrice >= 2000)
		{
			if (billPrice >= 5000)
			{
				if (billPrice >= 10000)
					cout << "\nYou got a discount of 10%. \nYour net payment is " << off(billPrice, 10) << '\n';
				else
					cout << "\nYou got a discount of 5%. \nYour net payment is " << off(billPrice, 5) << '\n';
			}
			else
				cout << "\nYou got a discount of 2%. \nYour net payment is " << off(billPrice, 2) << '\n';
		}
		else
			cout << "\nSorry! You couldn't receive any discount on this bill. \nYour net payment is " << off(billPrice, 0) << '\n';

		system("pause");

		return 0;

}

double off(float billPrice, float disc)
{
	float netPrice;

	netPrice = billPrice - ((billPrice / 100) * disc);

	return (netPrice);

}
