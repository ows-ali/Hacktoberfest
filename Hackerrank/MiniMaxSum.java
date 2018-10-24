/**
* https://www.hackerrank.com/challenges/mini-max-sum/problem
**/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class MiniMaxSum {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] arr = new int[5];
        
        
        for(int i = 0; i < 5;   i++)
            arr[i] = in.nextInt();
        int min=arr[0],max=0;
        for(int i=0;i<5;i++){
                if(arr[i]>max)
                   max = arr[i];
            if(arr[i]<min)
                    min = arr[i];
        }
        long maxSum = 0, minSum = 0;
        for(int i=0;i<5;i++){
            if(min == max && i!=4){
                maxSum +=arr[i];
                minSum +=arr[i];
            }
            if(arr[i] != min)
                maxSum += arr[i];
            if(arr[i] !=max)
                minSum +=arr[i];
        }
        
        System.out.print(minSum + " " + maxSum);
        in.close();
    }
}
