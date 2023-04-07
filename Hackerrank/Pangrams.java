/**
 * https://www.hackerrank.com/challenges/30-binary-numbers/copy-from/82667263
 **/


import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Pangrams {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine().replace("\\s+","").toLowerCase();
        BitSet b = new BitSet();

        for(char c: str.toCharArray()){
            if(c >='a' && c<='z'){
                b.set(c-'a');
            }
        }
        System.out.println(b.cardinality()==26?"pangram":"not pangram");
    }
}
