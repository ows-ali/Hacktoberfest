import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int nextInt = scan.nextInt();
        String nextString;

        for (int i = 0; i < nextInt; i++) {
            nextString = scan.next();
            for (int j = 0; j < nextString.length(); j++) {
                if (j % 2 == 0) {
                    System.out.print(nextString.charAt(j));
                }
            }
            System.out.print(" ");
            for (int j = 0; j < nextString.length(); j++) {
                if (j % 2 == 1) {
                    System.out.print(nextString.charAt(j));
                }
            }
            System.out.println();
        }
    }
}
