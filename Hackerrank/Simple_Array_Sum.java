/*
    https://www.hackerrank.com/challenges/simple-array-sum/problem
*/

import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution{

    static int sum=0;
    static int simpleArraySum(int ar[], int n){
        for(int i=0;i<n;i++)
            sum = sum+ar[i];
        return sum;
    }

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int ar[]=new int[n];
        for(int i=0;i<n;i++)
            ar[i]=sc.nextInt();
        int result = simpleArraySum(ar,n);
        System.out.println(result);
    }
}
