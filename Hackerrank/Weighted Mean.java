//https://www.hackerrank.com/challenges/s10-weighted-mean/submissions/code/124677449

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        int sum=0;
        int count=0;
        Scanner kb=new Scanner(System.in);
        int n=kb.nextInt();
        int[]b=new int[n];
        int[]c=new int[n];
        for(int i=0;i<n;i++)
        {
            b[i]=kb.nextInt();
        }
        for(int i=0;i<n;i++){
            c[i]=kb.nextInt();
            count=count+c[i];
            sum=sum+b[i]*c[i];
        
        }
        System.out.printf("%.1f",(float)sum/count);
    }
}
