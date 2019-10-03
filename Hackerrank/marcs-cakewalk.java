import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

import java.util.Arrays;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] calories = new int[n];
        for(int calories_i=0; calories_i < n; calories_i++){
            calories[calories_i] = in.nextInt();
        }
        Arrays.sort(calories); // ascending 1 2 3
        int j=0;
        long total=0;
        for(int i=n-1;i>=0;i--) // 3 2 1 
         {  total += calories[i] * Math.pow(2,j);
          j++;
         }
           System.out.println(total);
    }
}