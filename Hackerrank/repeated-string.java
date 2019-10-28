/**
* https://www.hackerrank.com/challenges/repeated-string/problem
**/


import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the repeatedString function below.
    static long repeatedString(String s, long n) {

        int stringOccurences = 0;
        Map<Integer, Integer> previousCount = new HashMap();
        long totalOccurences = 0;

        //Return 0 if it does not contain a
        if (!s.contains("a"))
            return 0;

        //If its contain only a
        if (s.matches("^[a]+$"))
            return n;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'a') {
                stringOccurences++;
            }

            previousCount.put(i, stringOccurences);
        }

        if ((n % s.length() != 0))
            totalOccurences = (n / s.length() * stringOccurences) + previousCount.get((int) (n % s.length() - 1));
        else
            totalOccurences = (n / s.length() * stringOccurences);

        return totalOccurences;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        long n = scanner.nextLong();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        long result = repeatedString(s, n);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
