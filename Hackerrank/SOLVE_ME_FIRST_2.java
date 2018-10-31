import java.io.*;
import java.util.*;


public class Solution {



    static int solveMeFirst(int a, int b) {
      return a+b;
      
	}

 public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a;
	 System.out.println("Enter First number");
        a = in.nextInt();
        int b;
	  System.out.println("Enter Second number");
        b = in.nextInt();
        int sum;
        sum = solveMeFirst(a, b);
        System.out.println("The Sum of Two Numbers"+sum);
	}
}
