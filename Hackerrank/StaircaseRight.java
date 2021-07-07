import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class StaircaseRight {

    static void staircase(int n) {

        for (int i = n; i > 0; i--) {

            for (int j = 1; j < i; j++)

                System.out.print(" ");

            for (int k = 0; k < n - i + 1; k++)

                System.out.print("#");

            System.out.print("\n");
        }

    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        staircase(n);

        scanner.close();
    }
}
