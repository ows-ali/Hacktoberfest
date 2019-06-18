import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class RecursiveDigitSum {

    // Complete the superDigit function below.
    static int superDigit(String n, int k) {
        return mySuperDigit(BigInteger.valueOf(k).multiply(mySuperDigit(new BigInteger(n)))).intValue();
    }
    
    static BigInteger mySuperDigit(BigInteger n) {
        if(n.compareTo(BigInteger.valueOf(10)) == -1) return n;
        return mySuperDigit(sumOfDigits(n));
    }
    
    static BigInteger sumOfDigits(BigInteger n) {
        BigInteger sum = new BigInteger("0");
        String str = n.toString();
        
        for(int i = 0; i < str.length(); i++)
            sum = sum.add(BigInteger.valueOf(Integer.parseInt("" + str.charAt(i))));
        
        return sum;
    }
    
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        String n = nk[0];

        int k = Integer.parseInt(nk[1]);

        int result = superDigit(n, k);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
