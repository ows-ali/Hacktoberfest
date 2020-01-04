import java.util.*;
// Here is the link to the Problem .
// https://www.hackerrank.com/challenges/java-if-else/problem

class Solution {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the Number");
        int N = scanner.nextInt();


        if ((N>=1) && (N<=100))
        {
            if (N % 2 != 0)
            {
                System.out.println("Weird");
            }

            if (N % 2 == 0)
            {

                if ((N > 2) && (N < 5)) {
                    System.out.println("Not Weird");
                } else if ((N > 6) && (N <= 20)) {
                    System.out.println("Weird");

                } else if ((N > 20)) {
                    System.out.println("Not Weird");

                } else {
                    System.out.println("yes");
                }
            }


        }
    }
}

