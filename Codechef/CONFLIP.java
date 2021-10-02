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
		    
		    int g = sc.nextInt();
		
		    while(g-->0){
		    
		        int i = sc.nextInt();
		        int n = sc.nextInt();
                int q = sc.nextInt();
                int r = n%2;
                int ans = n/2;
                if(r==0){
                    System.out.println(ans);
                }else{
                    if(i==q){
                        System.out.println(ans);
                    }else{
                        System.out.println(ans+1);
                    }
                }
		    }
		    
		}
	}
}
