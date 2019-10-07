/*

Pooja would like to withdraw X $US from an ATM. The cash machine will only accept the transaction if X is a multiple of 5, 
and Pooja's account balance has enough cash to perform the withdrawal transaction (including bank charges). 
For each successful withdrawal the bank charges 0.50 $US. Calculate Pooja's account balance after an attempted transaction.

Positive integer 0 < X <= 2000 - the amount of cash which Pooja wishes to withdraw.
Nonnegative number 0 <= Y <= 2000 with two digits of precision - Pooja's initial account balance.

Problem link - https://www.codechef.com/problems/HS08TEST

*/

#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    int amount = 0;
    double current = 0;

    std::cin >> amount >> current;
    
    if ((amount < 0 || amount > 2000) || (current < 0 || current > 2000))
    {
        std::cerr << "Not possible! Try again\n";
        exit(1);
    }
    else
    {
        double charge = 0.50;
        double new_current = 0;

        if (amount % 5 == 0)
        {
            if (current > amount + charge)
            {
                // Successful Transaction
                new_current = current - amount - charge;
                std::cout << std::fixed << std::setprecision(2) << new_current << std::endl;
            }
            else
            {
                // Insufficient Funds
                std::cout << std::fixed << std::setprecision(2) << current << std::endl;
            }
        }
        else
        {
            // Incorrect Withdrawal Amount (not multiple of 5)
            std::cout << std::fixed << std::setprecision(2) << current << std::endl;
        }
    }

    return 0;
}
