/**
* https://www.hackerrank.com/challenges/staircase/copy-from/70623634
**/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Staircase {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
         for(int k=n;k>0;k--){
	         for(int i=1;i<k;i++)
		        System.out.print(" ");
		     for(int j=0;j<n-k+1;j++)
               System.out.print("#");
            System.out.print("\n");
         }
        in.close();
    }
}
