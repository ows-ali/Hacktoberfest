/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0) {
			int num=sc.nextInt();
			int[] arr=new int[num];
			
			for (int i = 0; i < arr.length; i++) {
				arr[i]=sc.nextInt();
			}
			
			Arrays.sort(arr);
			
			int diff=Integer.MAX_VALUE;
		    for(int i=0;i<num-1;i++){
		        if(Math.abs(arr[i]-arr[i+1])<diff){
		            diff=Math.abs(arr[i]-arr[i+1]);
		        }
		    }
		    System.out.println(diff);
		}
		sc.close();
	}
}
