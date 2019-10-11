// Problem link -
// https://www.hackerrank.com/challenges/recursive-digit-sum/problem
// Submission link -
// https://www.hackerrank.com/challenges/recursive-digit-sum/submissions/code/109894964
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class ThePowerSum {

    static int solve(int X, int N, int i) {
        int temp = (int) Math.pow( i, N);
        if(temp > X)
            return 0;
        else if(temp == X)
            return 1;
        return solve(X, N, (i + 1)) + solve(X - temp, N, (i + 1));
    }
    static int powerSum(int X, int N) {
        return solve(X, N, 1); 
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        int X = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int N = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int result = powerSum(X, N);

        System.out.println(result);

        scanner.close();
    }
}
