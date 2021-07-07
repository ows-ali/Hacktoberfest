import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the plusMinus function below.
    static void plusMinus(int[] arr) {
     int l= arr.length;
      int pos=0;
      int neg=0;
      int zer=0;
      for(int i=0;i<l;i++){
        if(arr[i]==0){++zer;}
        else if(arr[i]>0){++pos;}
        else if(arr[i]<0){++neg;}
         }

        float pr=(float) pos/l;
        float nr=(float)neg/l;
        float zr=(float) zer/l;


       System.out.println(pr);
       System.out.println(nr);
       System.out.println(zr);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        plusMinus(arr);

        scanner.close();
    }
}
