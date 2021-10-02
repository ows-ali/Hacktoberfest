/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{   
	    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	    long sum, max = Long.MIN_VALUE;
	    
	    int n = Integer.parseInt(reader.readLine());
	    
	    long a[] = new long[n];
	    
	    for(int i = 0; i < n; i++){
	        a[i] = Long.parseLong(reader.readLine());
	    }
	    
	    Arrays.sort(a);
	    
	    for (int i = 1; i <= n ; i++){
	        sum = a[n-i]*i;
	        if(sum>max){
	            max = sum;
	        }
	    }
	    
	    System.out.println(max);
	}
}
