/**
* https://www.hackerrank.com/challenges/java-biginteger/problem
**/

import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class BigInteger {

    public static void main(String[] args) {      
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        BigInteger bi = new BigInteger(a);

        System.out.println(bi.add(new BigInteger(b)));
        System.out.println(bi.multiply(new BigInteger(b)));
    }
}
