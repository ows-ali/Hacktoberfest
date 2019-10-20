/*
Submission from Piboons (https://github.com/Piboons) for the problem Banking System (https://www.codechef.com/problems/BS)

"Problem:
All submissions for this problem are available.Lavina would like to withdraw X amount of cash from an ATM.
The cash machine will only accept the transaction if X is a multiple of 5, and Lavina's account balance has enough
cash to perform the withdrawal transaction (including bank charges). For each successful withdrawal the bank charges 0.50.
Calculate Lavina's account balance after an attempted transaction.

Input:
-Positive integer 0 < X <= 2000 the amount of cash which Lavina wishes to withdraw.
-Nonnegative number 0<= Y <= 2000 with two digits of precision - Lavina's initial account balance.

Output:
Output the account balance after the attempted transaction, given as a number with two digits of precision.
If there is not enough money in the account to complete the transaction, output the current bank balance."
*/

#include <iostream>
#include <string>
#include <iomanip>

void BS(std::string userInput) {
	int intAmountToWithdraw;
	std::string strAmountToWithdraw, strBalance;
	std::string::iterator it = userInput.begin();
	double doubleBalance, finalAmount;
	std::cout << std::fixed;	//We set precision of the output to have our two digits of precision
	std::cout << std::setprecision(2);
	while (*it != ' ') {	//We retrieve the amount to withdraw (before the ' ')
		strAmountToWithdraw.push_back(*it);
		it++;
	}
	while (it != userInput.end()) {	//We retrieve the balance (after the ' ')
		strBalance.push_back(*it);
		it++;
	}
	intAmountToWithdraw = std::stoi(strAmountToWithdraw);	//We convert our value to an integer form
	doubleBalance = std::stod(strBalance);	//We convert our value to a floating number form
	finalAmount = doubleBalance;	//In case withdraw is not possible
	if (intAmountToWithdraw % 5 != 0 || intAmountToWithdraw > doubleBalance || intAmountToWithdraw == 0) {	//Case 1: withdraw was not succesful
		std::cout << doubleBalance;
	}
	else {	//Case 2: withdraw was succesful
		finalAmount -= (intAmountToWithdraw + 0.50);
		std::cout << finalAmount;
	}
}