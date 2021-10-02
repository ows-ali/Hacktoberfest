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
		
		int t = Integer.parseInt(reader.readLine());
		boolean ans;
		while(t-->0){
		    
		    String s = reader.readLine();
		    int length = s.length();
		    char[] a = new char[26];
		    ans = true;
		    for(int i = 0; i < (length)/2; i++) {
		    	a[(int)s.charAt(i)-97]++;
		    	a[(int)s.charAt(length-i-1)-97]--;
		    }
		    for(int i = 0; i < 26; i++) {
		    	if(a[i]!=0) {
		    		System.out.println("NO");
		    		ans = false;
		    		break;
		    	}
		    }
		    if(ans) {
		    	System.out.println("YES");
		    }
		    
		}
	}
}
