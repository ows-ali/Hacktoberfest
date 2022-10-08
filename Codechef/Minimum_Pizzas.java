/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		while(t>0){
		    
		    int frind = scan.nextInt();
		    int slice = scan.nextInt();
		    int mul = frind*slice;
		    int need1 = mul/4;
		    if(mul%4!=0){
		        need1++;
		    }
		    System.out.println(need1);
		    t--;
		}
	}
}
