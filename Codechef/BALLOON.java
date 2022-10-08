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
        int N, n, c, flag;
        String[] s;
        int arr[];
        N = sc.nextInt();
        for (int i = 0; i < N; i++){
            c = flag = 0;
            n = sc.nextInt();
            sc.nextLine();
            s = sc.nextLine().split(" ");
            arr = new int[n];
            for( int al = 0; al < n; al++)
                arr[al] = Integer.valueOf(s[al]);
            while(c!=7){
                if(arr[flag] > 0 && arr[flag] < 8){
                    c++;
                    flag++;
                }
                else flag++;
            }
            System.out.println(flag);
        }
        sc.close();
	}
}
