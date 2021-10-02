/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		while(t-->0){
		    
	        int a = sc.nextInt();
	        int n = 5;
	        int n5 = 0;
	        while(a/n > 0){
	            n5 += a/n;
	            n *= 5;
	        }
	        System.out.println(n5);
		    
		}
	}
}
