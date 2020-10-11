import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

/*
https://www.hackerrank.com/challenges/lisa-workbook/problem
*/

public class Solution {

   
    static int workbook(int n, int k, int[] arr) {
        int page =1;
        int result=0;
        for(int i = 0;i<n;i++) {
            int ch=i+1;
            int problems = arr[i];
            int m = problems/k +1;
            int q = k;
            if((problems/k == 1 && problems%k == 0) || (problems<=k)) {
                m=1;
                q=problems;
            }
            else if(problems%k == 0 ) {
                m=problems/k;
            }
            
            int f = problems/k;
            
            int last =1;
            while(m > 0 ) {
                
                if((last== 1 || last< page) && page <= q ) {
                    result ++;
                }
                
                page++;
                m--;
                if(m == 1) {
                    last =q;
                    q= q+ (problems%k == 0?k:problems%k); 
                   
                                 
                }else {
                    q+=k;
                    last = q-k;
                }
                
            }
        }
        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int result = workbook(n, k, arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
