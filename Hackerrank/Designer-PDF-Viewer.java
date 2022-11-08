import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = 26;
        int h[] = new int[n];
        for(int h_i=0; h_i < n; h_i++){
            h[h_i] = in.nextInt();
        }
        String word = in.next();
        int mx = 0;
        for (int i = 0; i < word.length(); i++) {
            int f = h[(int) (word.charAt(i) - 'a')];
            if (f > mx) {
                mx = f;
            }
        }
        System.out.println((word.length() * mx));
    }
}
