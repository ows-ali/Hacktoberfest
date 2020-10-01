import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution {

    static int solve(int n, int[] s, int d, int m){
        // Complete this function
        int k=0,sum=0,count=0;
        for(int i=0;i<n;i++)
        {
            k=i;
            sum=0;
           for(int j=1;j<=m;j++)
           {
               if(k<n)
               {
                    sum=sum+s[k];
                    k++;
               }
           }
            if(sum==d)
                count++;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] s = new int[n];
        for(int s_i=0; s_i < n; s_i++){
            s[s_i] = in.nextInt();
        }
        int d = in.nextInt();
        int m = in.nextInt();
        int result = solve(n, s, d, m);
        System.out.println(result);
    }
}
