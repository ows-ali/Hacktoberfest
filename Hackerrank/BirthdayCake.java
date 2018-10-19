/**
* https://www.hackerrank.com/challenges/birthday-cake-candles/problem
**/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class BirthdayCake {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        int max = 0;
        for(int i = 0; i < n; i++){
            arr[i] = in.nextInt();
            if(max<arr[i])
                max = arr[i];
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(max == arr[i])
                 count++;
        }   
            
        System.out.println(count);
    }
}
