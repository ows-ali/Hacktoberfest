import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        BigInteger c = new BigInteger(a);

        System.out.println(c.add(new BigInteger(b)));
        System.out.println(c.multiply(new BigInteger(b)));
    }
}