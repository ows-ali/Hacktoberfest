import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the minimumBribes function below.
    static void minimumBribes(int[] q) {
        int count=0;
    
       
        for(int i=q.length-1;i>=0;i--)
            {
                if(q[i] != i+1)
                {
                if(i-1 >=0 && q[i-1] == i+1)
                {
                    count++;
                    int temp=q[i];
                    q[i] = q[i-1];
                    q[i-1] = temp; 
                }
                else if(i-2 >=0 && q[i-2] == i+1)
                {
                     count += 2;
                    
                    q[i-2] = q[i-1];
                    q[i-1] = q[i];   
                    q[i] = i+1;
                }
                else
                {
                    System.out.println("Too chaotic");
                    return;
                }
                }

            } 

        System.out.println(count);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] q = new int[n];

            String[] qItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n; i++) {
                int qItem = Integer.parseInt(qItems[i]);
                q[i] = qItem;
            }

            minimumBribes(q);
        }

        scanner.close();
    }
}
