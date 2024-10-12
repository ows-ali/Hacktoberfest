
/*
* https://www.hackerrank.com/challenges/java-stdin-and-stdout-1/problem
*/

import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int i = scan.nextInt();
        scan.nextLine(); // Consume the newline character after reading the int
        double d = scan.nextDouble();
        scan.nextLine(); // Consume the newline character after reading the double
        String s = scan.nextLine();

        System.out.println("String: " + s);
        System.out.println("Double: " + d);
        System.out.println("Int: " + i);
    }
}
