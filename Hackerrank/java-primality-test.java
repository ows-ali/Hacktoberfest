// problem url: https://www.hackerrank.com/challenges/java-primality-test/problem


import java.util.Scanner;


public class Solution {



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        System.out.println(scanner.nextBigInteger().isProbablePrime(100) ? "prime" : "not prime");
        scanner.close();

    }
}
