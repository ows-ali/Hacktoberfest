
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
			int N,M,X;
		
			while(T>0){
			    
	    N = scan.nextInt();
		M = scan.nextInt();
		X = scan.nextInt();
		int frame = 2*N + 2*M;
		int frameCost = frame*X;
		System.out.println(frameCost);
		T--;
		    
		}
		
	}
	
	
}
