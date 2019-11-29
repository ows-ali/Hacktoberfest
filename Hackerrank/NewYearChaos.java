/* This can be done recursively to make it far faster and pass more timing tests, may update this solution later*/
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
        int bribeCount = 0;
        for (int i = q.length-2; i >= 0; i--) {
            int personalBribeCount = 0;
            for (int j = i+1; j < q.length; j++) {
                if (q[i] > q[j]) {
                    if(personalBribeCount < 2) {
                        bribeCount++;
                        personalBribeCount++;
                    } else {
                        System.out.println("Too chaotic");
                        return;
                    }    
                }
            }
        }
        System.out.println(bribeCount);
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