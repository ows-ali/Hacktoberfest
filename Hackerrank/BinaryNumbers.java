/**
* https://www.hackerrank.com/challenges/30-binary-numbers/copy-from/82667263
**/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class BinaryNumbers {



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
        char[] binaryArray = Integer.toBinaryString(n).toCharArray();
        int max = 0, count = 0;
        for(int i = 0; i < binaryArray.length; i++){
            count = 0;
            //System.out.println((int)binaryArray[i]);
            if(((int) binaryArray[i]) == 49){
                for(int j = i; j < binaryArray.length; j++){
                    if(((int)binaryArray[j]) != 49)
                        break;
                    else
                        count++;
                }
            }
            //System.out.println(count);
            if(max < count)
                max = count;
        }
        System.out.println(max);
        scanner.close();
    }
}
