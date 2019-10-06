/*
      QUESTION : Pooja would like to withdraw X $US from an ATM. The cash machine will only accept the transaction if X is a multiple of 5, and Pooja's account balance has enough cash to perform the withdrawal transaction (including bank charges). For each successful withdrawal the bank charges 0.50 $US. Calculate Pooja's account balance after an attempted transaction.
      INPUT : Positive integer 0 < X <= 2000 - the amount of cash which Pooja wishes to withdraw.
	 Nonnegative number 0<= Y <= 2000 with two digits of precision - Pooja's initial account balance.
      OUTPUT : Output the account balance after the attempted transaction, given as a number with two digits of precision. If there is not enough money in the account to complete the transaction, output the current bank balance.

*/
#include <iostream>

using namespace std;


int main() 

{

	int x;
	
float y,z;
 
	cin>>x>>y;
				//User enters amount to be withdrawn and original amount in account

     	if(x>0 && x<=2000 && y>=0 && y<=2000)

	{

		if(x+0.5<y && x%5==0)
		//If entered amount is a multiple of 5 and, when added with the bank charges, is less than the account balance, then transaction happens
       		{
            
			z=y-x-0.50;
			
cout<<z;
        		//Output is the account balance after the transaction
		}
        
		else
		{

		 	cout<<y;
			//Output is the account balance
		}

    	}
	
	return 0;

}
