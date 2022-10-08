/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
	    //W -> Actual account balance
	    //X -> Income per month
	    //Y -> Deducted balance per month 
	    //Z -> Month to find final account balance 
	    	int W,X,Y,Z;
		  
		
		while(T>0){
		    
		    W = scan.nextInt();
		    X = scan.nextInt();
		    Y = scan.nextInt();
		    Z = scan.nextInt();
		    int income_in_Z_Month= X*Z;
		    int Debeted_in_Z_Month = Y*Z;
		    int final_Money = W+income_in_Z_Month - Debeted_in_Z_Month;
		    System.out.println(final_Money);
		    T--;
		}
	}
}
