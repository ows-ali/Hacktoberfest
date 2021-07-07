/* 
MY SOLUTION TO THE EQUAL ARRAY PROBLEM
LINK TO THE QUESTION : https://www.hackerrank.com/challenges/equality-in-a-array/problem?h_r=next-challenge&h_v=legacy
*/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the equalizeArray function below.
    static int equalizeArray(int[] arr) {
        int dup=-1, n = arr.length, count[] = new int[n/2];
        int j=-1;
        Arrays.sort(arr);
        for(int i=0; i<n-1; i++)
        {
            if(arr[i]==arr[i+1] && dup!=arr[i])
            {
                j+=1;
                dup=arr[i];
                count[j]++;
            }
            if(arr[i]==arr[i+1])
            {
                dup=arr[i];
                count[j]++;
            }
        }
        Arrays.sort(count);
        if(count[n/2-1]==0)
        {
            return (n-1);
        }
        return (n - count[n/2 - 1]);

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int result = equalizeArray(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
