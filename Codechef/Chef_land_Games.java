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
	    int t = scan.nextInt();
	    int r1,r2,r3,r4;
	    while(t>0){
	        
	        r1 = scan.nextInt();
	        r2 = scan.nextInt();
	        r3 = scan.nextInt();
	        r4 = scan.nextInt();
	        if(r1+r2+r3+r4==0){
	            System.out.println("IN");
	        }
	        else{
	            System.out.println("OUT");
	        }
	        t--;
	    }
	}
}
Footer
